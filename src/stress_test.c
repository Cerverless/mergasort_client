/*
 * Copyright (C) 2022  Davidson Francis <davidsondfgl@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.	 If not, see <http://www.gnu.org/licenses/>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toyws.h"
#include "../../mergasort_controller/src/messaging.h" // TODO decouple by using own version after maturity

// generic is amount of words when starting a job and id of word when adding a word
int send_message(struct tws_ctx ctx, int generic, char *message, int message_type, int lock_size, int job_nr) {
    //				printf("%d %s\n", count, token);

    char buffer[30];

    /*
    SEQUENCE OF MESSAGE FIELDS ARE:
    int message_nr = atoi(strtok(msg, DATA_DELIMITER)); 0 to add new word and 1 to get status and 2 to start job
    char *job_nr = strtok(NULL, DATA_DELIMITER);
    char *word_nr = strtok(NULL, DATA_DELIMITER);
    char *word = strtok(NULL, DATA_DELIMITER);
    char *lock_size = strtok(NULL, DATA_DELIMITER);
    */
    sprintf(buffer, "%d;%d;%d;%s;%d", message_type, job_nr, generic, message, lock_size);
    char *buff;
    int frm_type;
    size_t buff_size;

    buff = NULL;
    buff_size = 0;
    frm_type = 0;


    /* Send messages. */
    int result = tws_sendframe(&ctx, (uint8_t *) buffer, strlen(buffer), FRM_TXT);
    if (result < 0) {
        printf("Send: Failed\n");
        return 1;
    }

    /* Blocks until receive a single message. */
    if (tws_receiveframe(&ctx, &buff, &buff_size, &frm_type) < 0)
        if (buff == NULL) {
            fprintf(stderr, "Unable to receive message!\n");
            printf("I received: (%s) (type: %s)\n", *buff,
                   (frm_type == FRM_TXT ? "Text" : "Binary"));
        }

    free(buff);

    return 0;
}

int main(int argc, char *argv[]) {
    struct tws_ctx ctx;
    //	char msg1[] = "1;1;1;KAT";
    //
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file path>\n", argv[0]);
        exit(1);
    }

    FILE *fd;

    fd = fopen(argv[1], "r");

    char line[256];

    char *delims = " \n\t\r;.";
    // Check if the file was opened successfully.
    if (fd != NULL) {
        // Read each line from the file and store it in the
        // 'line' buffer.
        int count = 0;


        //if (tws_connect(&ctx, "172.25.106.171", 8080) < 0)
        if (tws_connect(&ctx, "172.25.111.17", 32222) < 0) {
            fprintf(stderr, "Unable to connect!\n");
            exit(1);
        }
        int job_nr = 3;
        int lock_size = 1000;
        // word not required when starting a job
                if(send_message(ctx, 30000, " ", 2, lock_size, job_nr) != 0) {
                    printf("Unable to register new job!\n");
                    exit(1);
                }

        while (fgets(line, sizeof(line), fd)) {
            char *token = strtok(line, delims);
            // Print each word to the standard output.
            while (token != NULL) {
                if(send_message(ctx, count++, token, 0, lock_size, job_nr) != 0) {
                    printf("Unable to register new word!\n");
                    exit(1);
                }


                token = strtok(NULL, delims);

            }
        }

        tws_close(&ctx);

        // Close the file stream once all lines have been
        // read.
        fclose(fd);
    }
    return (0);
}
