#include "stack.h"
#include "token.h"
#include "display.h"

void rechnen(T_token token)
{
    int a, b, result;

    switch (token.tok)
    {
        case NUMBER:
            push(token.val);
            break;

        case PLUS:
            if (pop(a) == 0 && pop(b) == 0) 
            {
                result = b + a;
                push(result);

            }

            break;

        case MINUS:
            if (pop(a) == 0 && pop(b) == 0) 
            {

                result = b - a;
                push(result);
            }
            break;

        case MULT:
            if (pop(a) == 0 && pop(b) == 0) 
            {
                result = b * a;
                push(result);
            }
            break;

        case DIV:
            if (pop(a) == 0 && pop(b) == 0) 
            {
                    result = b / a;
                    push(result);
                
            }
            break;
        case PRT:
        pop( a);




        case CLEAR:
            clear_stack();
            break;

        case DOUBLE:
            duplicate();
            break;

        case SWAP:
            swap();
            break;

        default:
            break;
    }
}
