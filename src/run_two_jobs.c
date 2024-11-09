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

/* ######################################################################################
   # HAS TO BE REWORKED TO WORK THE SAME WAY AS stress_test.c                           #
   ###################################################################################### */

int main(void)
{
        // JOB #1
	struct tws_ctx ctx;
	char msg11[] = "0;1;1;KAT";
	char msg12[] = "0;1;2;AAP";
	char msg13[] = "0;1;3;MUISHOND";
	char msg14[] = "0;1;4;MUIS";
	char msg15[] = "0;1;5;kobra";
	char msg16[] = "0;1;6;HOND";
	char msg17[] = "0;1;7;SLANG";
	char msg18[] = "0;1;8;ADDER";
	char msg19[] = "0;1;9;MUIS";
	char msg1_10[] = "0;1;10;LEEU";
	char msg1_11[] = "0;1;11;LUIPERD";
	char msg1_12[] = "0;1;12;WILDEHOND";
	char msg1_13[] = "0;1;13;WILDEBEES";
	char msg1_14[] = "0;1;14;BUFEL";
	char msg1_15[] = "0;1;15;ROOIBOK";
	char msg1_16[] = "0;1;16;BLESBOK";
	char msg1_17[] = "0;1;17;SPRINGBOK";
	char msg1_18[] = "0;1;18;SWARTWITPENS";
	char msg1_19[] = "0;1;19;STEENBOK";
	char msg1_20[] = "0;1;20;SKILPAD";
	char msg1_21[] = "0;1;21;KLIPSPRINGER";
	char msg1_22[] = "0;1;22;RIBBOK";
	char msg1_23[] = "0;1;23;SEEKOEI";
	char msg1_24[] = "0;1;24;KROKKODIL";
	char msg1_25[] = "0;1;25;VIS";
	char msg1_26[] = "0;1;26;VISAREND";
	char msg1_27[] = "0;1;27;IETERMAGOG";
	char msg1_28[] = "0;1;28;WILDEKAT";
	char msg1_29[] = "0;1;29;BYEVANGER";
	char msg1_30[] = "0;1;30;NEUSHOORNVOEL";
	char msg1_31[] = "0;1;31;AASVOEL";
	char msg1_32[] = "0;1;32;MISKRUIER";

        // JOB #2
	char msg111[] = "0;11;1;BOBBEJAAN";
	char msg112[] = "0;11;2;SEBRA";
	char msg113[] = "0;11;3;LUIPERD";
	char msg114[] = "0;11;4;AREND";

// 0 to add new word and 1 to get status and to receive 3 for job done
	/* Buffer params. */
	char *buff;
	int frm_type;
	size_t buff_size;

	buff      = NULL;
	buff_size = 0;
	frm_type  = 0;

	//if (tws_connect(&ctx, "172.26.68.178", 8080) < 0)
	if (tws_connect(&ctx, "172.26.72.119", 32222) < 0)
		fprintf(stderr, "Unable to connect!\n");

	/* Send messages. */
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg11, strlen(msg11), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg111, strlen(msg111), FRM_TXT) >= 0 ?
			"Success" : "Failed"));

	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg12, strlen(msg12), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg112, strlen(msg112), FRM_TXT) >= 0 ?
			"Success" : "Failed"));

	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg13, strlen(msg13), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg113, strlen(msg113), FRM_TXT) >= 0 ?
			"Success" : "Failed"));

	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg14, strlen(msg14), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg114, strlen(msg114), FRM_TXT) >= 0 ?
			"Success" : "Failed"));

	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg15, strlen(msg15), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg16, strlen(msg16), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg17, strlen(msg17), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg18, strlen(msg18), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg19, strlen(msg19), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_10, strlen(msg1_10), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_11, strlen(msg1_11), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_12, strlen(msg1_12), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_13, strlen(msg1_13), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_14, strlen(msg1_14), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_15, strlen(msg1_15), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_16, strlen(msg1_16), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_17, strlen(msg1_17), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_18, strlen(msg1_18), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_19, strlen(msg1_19), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_20, strlen(msg1_20), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_21, strlen(msg1_21), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_22, strlen(msg1_22), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_23, strlen(msg1_23), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_24, strlen(msg1_24), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_25, strlen(msg1_25), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_26, strlen(msg1_26), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_27, strlen(msg1_27), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_28, strlen(msg1_28), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_29, strlen(msg1_29), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_30, strlen(msg1_30), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_31, strlen(msg1_31), FRM_TXT) >= 0 ?
			"Success" : "Failed"));
	printf("Send: %s\n",
		(tws_sendframe(&ctx, (uint8_t*)msg1_32, strlen(msg1_32), FRM_TXT) >= 0 ?
			"Success" : "Failed"));



	/* Blocks until receive a single message. */
	if (tws_receiveframe(&ctx, &buff, &buff_size, &frm_type) < 0)
		fprintf(stderr, "Unable to receive message!\n");


	printf("I received: (%s) (type: %s)\n", buff,
		(frm_type == FRM_TXT ? "Text" : "Binary"));

	tws_close(&ctx);

	free(buff);
	return (0);
}
