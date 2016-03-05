//: Include Ardunio libraries
#include <SoftwareSerial.h>
#include <Servo.h>
#include <PololuMaestro.h>

//: Include Macro Definitions
#include "client.h"

//: variable declarations
SoftwareSerial maestro_serial(MAESTRO_RX, MAESTRO_TX);
MiniMaestro maestro(maestro_serial);

SoftwareSerial xbee(XBEE_RX, XBEE_TX);

int pos_x;
int pos_y;

int acc_x;
int acc_y;
int acc_z;

int z_dwn;
int c_dwn;

// leave in magic numbers?
void calibrate() {
    while (true) {
        Serial.println("Which servo?");
        Serial.setTimeout(3000);

        int servo = Serial.parseInt();

        if (0 <= servo && servo < NUM_SERVOS) {
            Serial.setTimeout(200);

            Serial.print("Tweaking servo: ");
            Serial.println(servo);

            while (true) {
                maestro.setTarget(servo, HOME_POS[servo]);

                int ctrl = Serial.parseInt();

                if (ctrl == 2) {
                    HOME_POS[servo] += 50;
                } else if (ctrl == 1) {
                    HOME_POS[servo] -= 50;
                } else if (ctrl == 0) {
                    continue;
                } else {
                    Serial.print("Final position: ");
                    Serial.println(HOME_POS[servo]);

                    break;
                }
            }
        } else {
            break;
        }
    }

    Serial.setTimeout(100);

    Serial.print("Final Positions: ");

    for (int servo = 0; servo < NUM_SERVOS; servo++) {
        Serial.print(HOME_POS[servo]);
        Serial.print(" ");
    }

    Serial.setTimeout(1000);
}

void exec(event_t events[], int len) {

    for (int idx = 0; idx < len; idx++) {
        int servo = events[idx].servo;
        int value = events[idx].value;

        if (servo == DELAY) {
            delay(value);
        } else {
            maestro.setTarget(servo, HOME_POS[servo] + value);
        }
    }
}

void setup() {
    Serial.begin(BAUD_RATE);
    maestro_serial.begin(BAUD_RATE);
    xbee.begin(BAUD_RATE);
    //exec(STAND, STAND_LENGTH);

    //delay(SETUP_DELAY_TIME);
    //exec(STAND_TO_CREEP_RIGHT, TO_CREEP_LENGTH);
    
}

void loop() {  
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_RIGHT_TO_STAND, TO_CREEP_LENGTH);
    exec(TURRET_UP_DOWN, 6);
    exec(TURRET_SIDE, 8);
    exec(TURN_LEFT, TURN_LENGTH);
    exec(TURN_LEFT, TURN_LENGTH);
    exec(TURN_LEFT, TURN_LENGTH);
    exec(TURN_LEFT, TURN_LENGTH);
    exec(STAND_TO_CREEP_RIGHT, TO_CREEP_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_LEFT, CREEP_FORWARD_LENGTH);
    exec(CREEP_FORWARD_RIGHT, CREEP_FORWARD_LENGTH);
    exec(CREEP_LEFT_TO_STAND, TO_CREEP_LENGTH);
    exec(TURRET_UP_DOWN, 6);
    exec(TURRET_SIDE, 8)
    exec(TURN_RIGHT, TURN_LENGTH);
    exec(TURN_RIGHT, TURN_LENGTH);
    exec(TURN_RIGHT, TURN_LENGTH);
    exec(TURN_RIGHT, TURN_LENGTH);
    exec(STAND_TO_CREEP_RIGHT, TO_CREEP_LENGTH);
    //calibrate();
    /*

    if (INPUT_SIZE <= xbee.available()) {
        pos_x = xbee.read();
        pos_y = xbee.read();

        acc_x = xbee.read();
        acc_y = xbee.read();
        acc_z = xbee.read();

        z_dwn = xbee.read();
        c_dwn = xbee.read();
    }

    for (int cnt = 0; cnt < 2; cnt++) {
        turn_left();
    }

    delay(LOOP_DELAY_TIME);

    for (int cnt = 0; cnt < 2; cnt++) {
        turn_right();
    }

    delay(LOOP_DELAY_TIME);

    */
}
