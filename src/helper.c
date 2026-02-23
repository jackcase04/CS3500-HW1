#include "helper.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int scientific(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else if (val == '.') state = 3;
                else return -1;

                break;
            case 3:
                if (isdigit(val)) state = 4;
                else return -1;

                break;
            case 4:
                if (isdigit(val)) state = 4;
                else if (val == 'E') state = 5;
                else return -1;

                break;
            case 5:
                if (isdigit(val) && val != '0') state = 7;
                else if (val == '-' || val == '+') state = 6;
                else return -1;

                break;

            case 6:
                if (isdigit(val) && val != '0') state = 7;
                else return -1;

                break;

            case 7:
                if (isdigit(val)) state = 7;
                else return -1;

                break;
        }
    }

    if (state == 7) {
        return 1;
    }
}

int decimal(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else if (val == '.') state = 3;
                else return -1;

                break;
            case 3:
                if (isdigit(val)) state = 4;
                else return -1;

                break;
            case 4:
                if (isdigit(val)) state = 4;
                else return -1;

                break;
        }
    }

    if (state == 4) {
        return 1;
    }
}

int integer(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 2;
                else if (val == '-' || val == '+') state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;
            case 2:
                if (isdigit(val)) state = 2;
                else return -1;
        }
    }

    if (state == 2) {
        return 1;
    }
}

int keyword(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (val == 'F') state = 1;
                else if (val == 'I') state = 9;
                else if (val == 'E') state = 11;
                else if (val == 'W') state = 17;
                else return -1;

                break;

            case 1:
                if (val == 'U') state = 2;
                else return -1;

                break;

            case 2:
                if (val == 'N') state = 3;
                else return -1;

                break;

            case 3:
                if (val == 'C') state = 4;
                else return -1;

                break;

            case 4:
                if (val == 'T') state = 5;
                else return -1;

                break;

            case 5:
                if (val == 'I') state = 6;
                else return -1;

                break;

            case 6:
                if (val == 'O') state = 7;
                else return -1;

                break;

            case 7:
                if (val == 'N') state = 8;
                else return -1;

                break;

            case 8:
                // Another value in final state means failure
                return -1;

                break;

            case 9:
                if (val == 'F') state = 10;
                else return -1;

                break;

            case 10:
                return -1;

                break;

            case 11:
                if (val == 'L') state = 12;
                else if (val == 'N') state = 15;
                else return -1;

                break;

            case 12:
                if (val == 'S') state = 13;
                else return -1;

                break;

            case 13:
                if (val == 'E') state = 14;
                else return -1;

                break;

            case 14:
                return -1;

                break;

            case 15:
                if (val == 'D') state = 16;
                else return -1;

                break;

            case 16:
                return -1;

                break;

            case 17:
                if (val == 'H') state = 18;
                else if (val == 'R') state = 22;
                else return -1;

                break;

            case 18:
                if (val == 'I') state = 19;
                else return -1;

                break;

            case 19:
                if (val == 'L') state = 20;
                else return -1;

                break;

            case 20:
                if (val == 'E') state = 21;
                else return -1;

                break;

            case 21:
                return -1;

                break;

            case 22:
                if (val == 'I') state = 23;
                else return -1;

                break;

            case 23:
                if (val == 'T') state = 24;
                else return -1;

                break;

            case 24:
                if (val == 'E') state = 25;
                else return -1;

                break;

            case 25:
                return -1;

                break;
        }
    }

    if (state == 8 || state == 10 || state == 14 || state == 16 || state == 21 || state == 25) {
        return 1;
    }
}

int hexadecimal(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val) || (val >= 'A' && val <= 'F')) state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val) || (val >= 'A' && val <= 'F')) state = 1;
                else if (val == 'H') state = 2;
                else return -1;

                break;
            case 2:
                return -1;
        }
    }

    if (state == 2) {
        return 1;
    }
}

int charliteral(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val) || (val >= 'A' && val <= 'F')) state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val) || (val >= 'A' && val <= 'F')) state = 2;
                else return -1;

                break;
            case 2:
                if (val == 'X') state = 3;
                else return -1;
                break;

            case 3:
                return -1;
                break;
        }
    }

    if (state == 3) {
        return 1;
    }
}

int aircraft(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (
                    val == 'A'
                    || val == 'G'
                    || val == 'J'
                    || val == 'D'
                    || val == 'P'
                    || val == 'L'
                ) state = 1;
                else return -1;

                break;
            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;
            case 2:
                if (isdigit(val)) state = 3;
                else if (
                    val == 'A'
                    || val == 'K'
                    || val == 'M'
                    || val == 'N'
                    || val == 'Y'
                ) state = 4;
                else return -1;

                break;
            case 3:
                if (
                    val == 'A'
                    || val == 'K'
                    || val == 'M'
                    || val == 'N'
                    || val == 'Y'
                ) state = 4;
                else return -1;

                break;
            case 4:
                if (isdigit(val)) state = 5;
                else return -1;

                break;
            case 5:
                if (val == '-') state = 7;
                else if (isdigit(val)) state = 6;
                else return -1;

                break;

            case 6:
                if (val == '-') state = 7;
                else return -1;

                break;

            case 7:
                if (
                    val == 'A'
                    || val == 'G'
                    || val == 'J'
                    || val == 'D'
                    || val == 'P'
                    || val == 'L'
                ) state = 8;
                else return -1;

                break;
            case 8:
                return -1;
                break;
        }
    }

    if (state == 4 || state == 5 || state == 6 || state == 8) {
        return 1;
    }
}

int identifier(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isalpha(val)) state = 1;
                else return -1;

                break;
            case 1:
                if (isalnum(val) || val == '_') state = 1;
                else return -1;

                break;
        }
    }

    if (state == 1) {
        return 1;
    }
}

int string_literal(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (val == '"') state = 1;
                
                else return -1;

                break;
            case 1:
                if (val != ' ' && val != '"') state = 2;
                else return -1;

                break;
            case 2:
                if (val != ' ' && val != '"') state = 2;
                else if (val == '"') state = 3;
                else return -1;

                break;
            case 3:
                return -1;

                break;
        }
    }

    if (state == 3) {
        return 1;
    }
}

int phone_number(char string[]) {
    int len = strlen(string);
    int state = 0;
    char val;

    for (int i = 0; i < len; ++i) {
        val = string[i];

        switch (state) {
            case 0:
                if (isdigit(val)) state = 1;
                else if (val == '(') state = 4;
                else return -1;

                break;

            case 1:
                if (isdigit(val)) state = 2;
                else return -1;

                break;

            case 2:
                if (isdigit(val)) state = 3;
                else return -1;

                break;

            case 3:
                if (val == '.') state = 8;
                else if (val == '-') state = 12;
                else return -1;

                break;

            case 4:
                if (isdigit(val)) state = 5;
                else return -1;

                break;

            case 5:
                if (isdigit(val)) state = 6;
                else return -1;

                break;

            case 6:
                if (isdigit(val)) state = 7;
                else return -1;

                break;

            case 7:
                if (val == ')') state = 12;
                else return -1;

                break;

            case 8:
                if (isdigit(val)) state = 9;
                else return -1;

                break;

            case 9:
                if (isdigit(val)) state = 10;
                else return -1;

                break;

            case 10:
                if (isdigit(val)) state = 11;
                else return -1;

                break;

            case 11:
                if (val == '.') state = 16;
                else return -1;

                break;

            case 12:
                if (isdigit(val)) state = 13;
                else return -1;

                break;

            case 13:
                if (isdigit(val)) state = 14;
                else return -1;

                break;

            case 14:
                if (isdigit(val)) state = 15;
                else return -1;

                break;

            case 15:
                if (val == '-') state = 16;
                else return -1;

                break;

            case 16:
                if (isdigit(val)) state = 17;
                else return -1;

                break;

            case 17:
                if (isdigit(val)) state = 18;
                else return -1;

                break;

            case 18:
                if (isdigit(val)) state = 19;
                else return -1;

                break;

            case 19:
                if (isdigit(val)) state = 20;
                else return -1;

                break;

            case 20:
                return -1;

                break;
        }
    }

    if (state == 20) {
        return 1;
    }
}

void lexx(char string[]) {
    if (scientific(string) == 1) {
        printf("Scientific\n");
    } else if (decimal(string) == 1) {
        printf("Decimal\n");
    } else if (integer(string) == 1) {
        printf("Integer\n");
    } else if (keyword(string) == 1) {
        printf("Keyword\n");
    } else if (hexadecimal(string) == 1) {
        printf("Hexadecimal\n");
    } else if (charliteral(string) == 1) {
        printf("Character\n");
    } else if (aircraft(string) == 1) {
        printf("Aircraft\n");
    } else if (identifier(string) == 1) {
        printf("Identifier\n");
    } else if (string_literal(string) == 1) {
        printf("String\n");
    } else if (phone_number(string) == 1) {
        printf("Phone\n");
    } else {
        printf("INVALID!\n");
    }
}