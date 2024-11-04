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


int main(int argc, char *argv[])
{
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

	char* delims = " \n\t\r;."; 
	// Check if the file was opened successfully.
	if (fd != NULL) {
		// Read each line from the file and store it in the
		// 'line' buffer.
		int count = 1;


		//if (tws_connect(&ctx, "172.26.68.178", 8080) < 0)
		if (tws_connect(&ctx, "172.26.72.119", 32222) < 0)
			fprintf(stderr, "Unable to connect!\n");

		while (fgets(line, sizeof(line), fd)) {
			char* token = strtok(line, delims);
			// Print each word to the standard output.
			while (token != NULL) {
			//	printf("%d %s\n", count++, token);

				char buffer[30];
				sprintf(buffer, "0;3;%d;%s", count++, token);     
				// 0 to add new word and 1 to get status and to receive 3 for job done
				/* Buffer params. */
				char *buff;
				int frm_type;
				size_t buff_size;

				buff      = NULL;
				buff_size = 0;
				frm_type  = 0;


				/* Send messages. */
				int result = tws_sendframe(&ctx, (uint8_t*)buffer, strlen(buffer), FRM_TXT);
				if (result < 0) {
					printf("Send: %s\n",
							(result >= 0 ?
							  "Success" : "Failed"));
				}

				/* Blocks until receive a single message. */
				if (tws_receiveframe(&ctx, &buff, &buff_size, &frm_type) < 0)
					if (buff == NULL) { 
						fprintf(stderr, "Unable to receive message!\n");
						printf("I received: (%s) (type: %s)\n", buff,
								(frm_type == FRM_TXT ? "Text" : "Binary"));
					}


				token = strtok(NULL, delims);
				free(buff); 

			}

		}

		tws_close(&ctx);

		// Close the file stream once all lines have been
		// read.
		fclose(fd);
	}
	return (0);
}
