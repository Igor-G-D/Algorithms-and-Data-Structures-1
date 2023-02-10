// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

bool isValid(char * s){

    int bracket_1 = 0;
    int bracket_2 = 0;
    int bracket_3 = 0;
    int previous;
    int strlength = strlen(s);
    int order[strlength];
    int jump = 1;
    int counter = 0 ;
    int i;

    for(i=0;i<strlength;i++) {
        if(s[i] == '(') {
            bracket_1++;
            order[counter]=1;
            counter++;
        }
        else if(s[i] == '[') {
            bracket_2++;
            order[counter]=2;
            counter++;
        }
        else if(s[i] == '{') {
            bracket_3++;
            order[counter]=3;
            counter++;
        }
        else if(s[i] == ')') {
            bracket_1--;
            if(order[counter-jump] == 1) {
                jump++;
            } else {
                return 0;
            }
        }
        else if(s[i] == ']') {
            bracket_2--;
            if(order[counter-jump] == 2) {
                jump++;
            } else {
                return 0;
            }
        }
        else if(s[i] == '}') {
            bracket_3--;
            if(order[counter-jump] == 3) {
                jump++;
            } else {
                return 0;
            }
        }
    }

    if(bracket_1 == 0 && bracket_2 == 0 && bracket_3 == 0) {
        return 1;
    } else {
        return 0;
    }
}