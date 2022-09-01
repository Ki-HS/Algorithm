#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define raw1 "Suzie_CIF_352x288.raw"
#define raw2 "barbara(512x512).raw"
#define raw3 "gLenna256_256.raw"

#define conveted_raw1 "result_Suzie_CIF_352x288.raw"
#define conveted_raw2 "result_barbara(512x512).raw"
#define conveted_raw3 "result_gLenna256_256.raw"

char input_data[512][512];
char output_data[512][512];

void readFile() {
	FILE* input = fopen(raw1, "rb");;

	if (!input) {
		std::cout << "File Not Exists\n";
		return;
	}
	fread(input_data, sizeof(char), 512 * 512, input);

	for (int i = 0; i < 512; i++) {
		for(int j=0; j<512; j++){
			output_data[i][j] = 255 - input_data[i][j];
		}
	}
	fclose(input);
}

void saveFile() {
	FILE* output = fopen(conveted_raw1,"wb");
	fwrite(output_data, sizeof(char), 512 * 512, output);
	fclose(output);
}