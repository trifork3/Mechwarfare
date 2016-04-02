#define EVENT_DELAY_TIME  100
#define HOME_DELAY_TIME   10

#define FRONT_LEFT_HIP_HOME_POS    6104
#define FRONT_LEFT_KNEE_HOME_POS   5476
#define FRONT_LEFT_ANKLE_HOME_POS  4350
#define FRONT_RIGHT_HIP_HOME_POS   6244
#define FRONT_RIGHT_KNEE_HOME_POS  5992
#define FRONT_RIGHT_ANKLE_HOME_POS 5950
#define BACK_RIGHT_HIP_HOME_POS    5322
#define BACK_RIGHT_KNEE_HOME_POS   4674
#define BACK_RIGHT_ANKLE_HOME_POS  3930
#define BACK_LEFT_HIP_HOME_POS     6388
#define BACK_LEFT_KNEE_HOME_POS    5634
#define BACK_LEFT_ANKLE_HOME_POS   8272
#define TURRET_PAN_HOME_POS        6000
#define TURRET_TILT_HOME_POS       5850

#define CREEP_ROTATE_ANGLE       2000
#define CREEP_RAISE_KNEE_ANGLE   2000
#define CREEP_RAISE_ANKLE_ANGLE  1200
#define CREEP_PUSH_ANKLE_ANGLE   900
#define CREEP_PUSH_KNEE_ANGLE   -200
#define TURNING_V_ANGLE          800
#define TURNING_H_ANGLE          1000
#define TURRET_TILT_ANGLE        200

#define TURRET_PAN_LEFT   5500
#define TURRET_PAN_CENTER 6000
#define TURRET_PAN_RIGHT  6500

#define STANCE_LEN        15
#define HOME_TO_CREEP_LEN 16
#define CREEP_LEN         24
#define CREEP_TO_HOME_LEN 16
#define TURRET_V_LEN      6
#define TURRET_H_LEN      8
#define TURN_LEN          22

enum stance_t {
    FRONT,
    BACK,
    RIGHT,
    LEFT,
    HOME
};

enum pservo_t {
    DELAY             = -1,
    FRONT_LEFT_HIP    = 0,
    FRONT_LEFT_KNEE   = 1,
    FRONT_LEFT_ANKLE  = 2,
    FRONT_RIGHT_HIP   = 3,
    FRONT_RIGHT_KNEE  = 4,
    FRONT_RIGHT_ANKLE = 5,
    BACK_RIGHT_HIP    = 6,
    BACK_RIGHT_KNEE   = 7,
    BACK_RIGHT_ANKLE  = 8,
    BACK_LEFT_HIP     = 9,
    BACK_LEFT_KNEE    = 10,
    BACK_LEFT_ANKLE   = 11,
    TURRET_PAN        = 12,
    TURRET_TILT       = 13,
    NUM_SERVOS        = 14
};

struct event_t {
    pservo_t servo;
    int value;
};

int HOME_POS[] = {
    [FRONT_LEFT_HIP]    = FRONT_LEFT_HIP_HOME_POS,
    [FRONT_LEFT_KNEE]   = FRONT_LEFT_KNEE_HOME_POS,
    [FRONT_LEFT_ANKLE]  = FRONT_LEFT_ANKLE_HOME_POS,
    [FRONT_RIGHT_HIP]   = FRONT_RIGHT_HIP_HOME_POS,
    [FRONT_RIGHT_KNEE]  = FRONT_RIGHT_KNEE_HOME_POS,
    [FRONT_RIGHT_ANKLE] = FRONT_RIGHT_ANKLE_HOME_POS,
    [BACK_RIGHT_HIP]    = BACK_RIGHT_HIP_HOME_POS,
    [BACK_RIGHT_KNEE]   = BACK_RIGHT_KNEE_HOME_POS,
    [BACK_RIGHT_ANKLE]  = BACK_RIGHT_ANKLE_HOME_POS,
    [BACK_LEFT_HIP]     = BACK_LEFT_HIP_HOME_POS,
    [BACK_LEFT_KNEE]    = BACK_LEFT_KNEE_HOME_POS,
    [BACK_LEFT_ANKLE]   = BACK_LEFT_ANKLE_HOME_POS,
    [TURRET_PAN]        = TURRET_PAN_HOME_POS,
    [TURRET_TILT]       = TURRET_TILT_HOME_POS
};

event_t HOME_STANCE[] = {
    {FRONT_RIGHT_HIP,   0},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {FRONT_LEFT_HIP,    0},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {BACK_RIGHT_HIP,    0},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {BACK_LEFT_HIP,     0},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {DELAY,             HOME_DELAY_TIME}
};

event_t FRONT_STANCE[] = {
    {FRONT_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {FRONT_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_KNEE,    0},
    {FRONT_LEFT_ANKLE,   0},
    {BACK_RIGHT_HIP,     0},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {BACK_LEFT_HIP,      0},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {DELAY,              EVENT_DELAY_TIME}
};

event_t BACK_STANCE[] = {
    {FRONT_RIGHT_HIP,   0},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {FRONT_LEFT_HIP,    0},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {BACK_RIGHT_HIP,    CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {BACK_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t LEFT_STANCE[] = {
    {FRONT_RIGHT_HIP,   CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {FRONT_LEFT_HIP,    0},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {BACK_RIGHT_HIP,    0},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {BACK_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t RIGHT_STANCE[] = {
    {FRONT_RIGHT_HIP,    0},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {FRONT_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_KNEE,    0},
    {FRONT_LEFT_ANKLE,   0},
    {BACK_RIGHT_HIP,    -CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {BACK_LEFT_HIP,      0},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {DELAY,              EVENT_DELAY_TIME}
};


event_t HOME_TO_CREEP_F[] = {
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t HOME_TO_CREEP_B[] = {
    {BACK_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,   0},
    {BACK_LEFT_ANKLE,  0},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,   CREEP_ROTATE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,  0},
    {BACK_RIGHT_ANKLE, 0},
    {DELAY,            EVENT_DELAY_TIME}

};

event_t HOME_TO_CREEP_L[] = {
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,   CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t HOME_TO_CREEP_R[] = {
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,   CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    -CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {DELAY,              EVENT_DELAY_TIME}
};

event_t CREEP_FORWARD_FROM_R[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,     0},
    {FRONT_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {BACK_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,    CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,      CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME}

};

event_t CREEP_FORWARD_FROM_L[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     0},
    {FRONT_RIGHT_HIP,   CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t CREEP_BACKWARD_FROM_R[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,   0},
    {BACK_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t CREEP_BACKWARD_FROM_L[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {BACK_LEFT_KNEE,     CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,    CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,      0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     CREEP_PUSH_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,     0},
    {BACK_RIGHT_HIP,    -CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME}
};

event_t CREEP_LEFT_FROM_F[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {FRONT_LEFT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,   CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,     0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,    CREEP_PUSH_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    0},
    {BACK_LEFT_HIP,     -CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_LEFT_KNEE,    0},
    {FRONT_LEFT_ANKLE,   0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,   CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,     CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {DELAY,              EVENT_DELAY_TIME}

};

event_t CREEP_LEFT_FROM_B[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {BACK_LEFT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,   CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,    CREEP_PUSH_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {FRONT_LEFT_HIP,    CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t CREEP_RIGHT_FROM_F[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,     0},
    {BACK_RIGHT_HIP,     CREEP_ROTATE_ANGLE},
    {BACK_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,    CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,      -CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME}

};

event_t CREEP_RIGHT_FROM_B[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     0},
    {FRONT_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t CREEP_F_TO_HOME[] = {
  {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
  {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_LEFT_HIP,    0},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_LEFT_KNEE,   0},
  {FRONT_LEFT_ANKLE,  0},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
  {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_RIGHT_HIP,   0},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_RIGHT_KNEE,  0},
  {FRONT_RIGHT_ANKLE, 0},
  {DELAY,             EVENT_DELAY_TIME}


};

event_t CREEP_B_TO_HOME[] = {
  {BACK_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
  {BACK_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_LEFT_HIP,    0},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_LEFT_KNEE,   0},
  {BACK_LEFT_ANKLE,  0},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
  {BACK_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_RIGHT_HIP,   0},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_RIGHT_KNEE,  0},
  {BACK_RIGHT_ANKLE, 0},
  {DELAY,            EVENT_DELAY_TIME}

};

event_t CREEP_L_TO_HOME[] = {
    {FRONT_LEFT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,   0},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,  0},
    {FRONT_LEFT_ANKLE, 0},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,    0},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,   0},
    {BACK_LEFT_ANKLE,  0},
    {DELAY,            EVENT_DELAY_TIME}
};

event_t CREEP_R_TO_HOME[] = {
    {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,   0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t TURRET_V[] = {
    {TURRET_TILT,   700},
    {DELAY,         1000},
    {TURRET_TILT,  -700},
    {DELAY,         1000},
    {TURRET_TILT,   0},
    {DELAY,         1000}
};

event_t TURRET_H[] = {
    {TURRET_PAN,   1000},
    {DELAY,        300},
    {TURRET_PAN,  -1000},
    {DELAY,        600},
    {TURRET_PAN,   1000},
    {DELAY,        355},
    {TURRET_PAN,   0},
    {DELAY,        300}
};

event_t TURN_L[] = {
    {FRONT_LEFT_KNEE, TURNING_V_ANGLE},
    {BACK_RIGHT_KNEE, TURNING_V_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  -TURNING_H_ANGLE},
    {BACK_RIGHT_HIP,  -TURNING_H_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE, 0},
    {BACK_RIGHT_KNEE, 0},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  0},
    {BACK_RIGHT_HIP,  0},

    {FRONT_RIGHT_KNEE, TURNING_V_ANGLE},
    {BACK_LEFT_KNEE,   TURNING_V_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  -TURNING_H_ANGLE},
    {BACK_LEFT_HIP,    -TURNING_H_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE, 0},
    {BACK_LEFT_KNEE,   0},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  0},
    {BACK_LEFT_HIP,    0}
};

event_t TURN_R[] = {
    {FRONT_LEFT_KNEE, TURNING_V_ANGLE},
    {BACK_RIGHT_KNEE, TURNING_V_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  TURNING_H_ANGLE},
    {BACK_RIGHT_HIP,  TURNING_H_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE, 0},
    {BACK_RIGHT_KNEE, 0},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  0},
    {BACK_RIGHT_HIP,  0},

    {FRONT_RIGHT_KNEE, TURNING_V_ANGLE},
    {BACK_LEFT_KNEE,   TURNING_V_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  TURNING_H_ANGLE},
    {BACK_LEFT_HIP,    TURNING_H_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE, 0},
    {BACK_LEFT_KNEE,   0},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  0},
    {BACK_LEFT_HIP,    0}
};
