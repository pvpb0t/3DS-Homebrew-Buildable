
#include <3ds.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	gfxInitDefault();


	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	printf("\x1b[16;20HHello noob");

	printf("\x1b[30;16HPress Start to exit.");
				printf("\x1b[6;3HPress KEY_SELECT to go to home menu");



	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();



		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		if (kDown & KEY_A) {
			printf("\x1b[2;16HYou Clicked some shit");
		}

		if(kDown & KEY_SELECT){
			aptJumpToHomeMenu();

		}
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
