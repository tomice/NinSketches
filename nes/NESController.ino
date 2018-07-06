/*
Credit goes to Mike Rogers at www.themikerogers.com for the tutorial
and to all those who worked on the NES/SNES Arduino library.
For the library, head to code.google.com/p/nespad
*/

#include <NESpad.h>

byte channelState[] = {0, 0, 0, 0, 0, 0};
NESpad nintendo = NESpad(2, 3, 4);
int state = 0;

// Required for sketch. Activates during power on. No initialization needed
void setup() {}

void loop() {
    
    state = nintendo.buttons();
    Keyboard.set_key1(0);
    channelState[0] = 0;
    Keyboard.set_key2(0);
    channelState[1] = 0;
    Keyboard.set_key3(0);
    channelState[2] = 0;
    Keyboard.set_key4(0);
    channelState[3] = 0;
    Keyboard.set_key5(0);
    channelState[4] = 0;
    Keyboard.set_key6(0);
    channelState[5] = 0;
    
    // Sets buttons to keyboard equivalent based on current state
    if (state & NES_A) {
        setChannel(KEY_A);
    }
    if (state & NES_B) {
        setChannel(KEY_B);
    }
    if (state & NES_UP) {
        setChannel(KEY_UP);
    }
    if (state & NES_DOWN) {
        setChannel(KEY_DOWN);
    }
    if (state & NES_LEFT) {
        setChannel(KEY_LEFT);
    }
    if (state & NES_RIGHT) {
        setChannel(KEY_RIGHT);
    }
    if (state & NES_SELECT) {
        setChannel(KEY_TAB);
    }
    if (state & NES_START) {
        setChannel(KEY_SPACE);
    }
    Keyboard.send_now();
}

// Assigns the received byte code
void setChannel(byte button) {
    for (int i = 0; i < 6; i++) {
        int buttonPressed = 0;
        if (channelState[i] == 0) {
            switch (i) {
                case 0:
                    Keyboard.set_key1(button);
                    channelState[i] = 1;
                    buttonPressed = 1;
                    break;
                case 1:
                    Keyboard.set_key2(button);
                    channelState[i] = 1;
                    buttonPressed = 1;
                    break;
                case 2:
                    Keyboard.set_key3(button);
                    channelState[i] = 1;
                    buttonPressed = 1;
                    break;
                case 3:
                    Keyboard.set_key4(button);
                    channelState[i] = 1;
                    buttonPressed = 1;
                    break;
                case 4:
                    Keyboard.set_key5(button);
                    channelState[i] = 1;
                    buttonPressed = 1;
                    break;
                case 5:
                    Keyboard.set_key6(button);
                    channelState[i] = 1;
                    buttonPressed = 1;
                    break;
            }
            if (buttonPressed == 1) {
                break;
            }
        }
    }
}