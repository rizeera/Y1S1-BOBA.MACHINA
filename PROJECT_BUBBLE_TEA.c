#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[10];
int input_temp;
int tempS;

/*
    //  INPUT / OUTPUT //
    char input[1] ;
    int input_temp;
    int TOPPING_amount;
    

    REFILLING THE MACHINE
    int TEA_price[6] = { 30,30,30,45,40,35 }; //base on Medium cup size's price
    int FLAVOR_price[4] = { 0,5,5,10 };
    int TOPPING_price[4] = { 5,15,10,10 };
    int TOPPING_unit[4] = { 0,0,0,0 }; //OR JUST FILL THE VALUE LATER;

    MONEY ARRAY 
    int MONEY_value[5] = { 100,50,20,10,5 };
    int MONEY_machine[5] = { 0,0,0,0,0 };
    int MONEY_inse  rt[5];
    int MONEY_changes[5];
    
    MONEY 
    int TOTAL_insert = 0;
    int TOTAL_change = 0;
   */
int TOTAL_price = 0; /*


                                                                                            /////
    int SELECTION_ARRAY[] = { (TEA_input) , (FLAVOR_input) , (TOPPING_1ST) , (TOPPING_2ND)};///// MAY NOT NEED IT
                                                                                            ///// COULD USE NEW FUNCTION TO PRINT SELECTED MENU //////////
                                                                                           
    */

int main()
{
    /* MAIN MENU */

    /* ASK FOR BASSE TEA */

    printf("Please select your base tea (enter 'q' to exit program): ");
    scanf("%s", input);
TEA_SCAN:
    if (input[1] != '\0')
    {
        input[0] = '\0';
        goto RE_SCAN_TEA;
    }
    else
    {
        if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
        {
            tempS = 5;
        }
        else
            tempS = 0;
    }

    input_temp = atoi(input) + (tempS - 5);

    if ((input_temp >= 0 && input_temp <= 5) || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0')
        {
            return 0;
        }
        //USE 'NEW_INTEGER' to position in the FLAVOR_PRICE_ARRAY;
        //ADD PRICE IN THE  "TOTAL_PRICE";
        //ASSIGN NEW_INTEGER to SELECTION_ARRAY
    }
    else

    RE_SCAN_TEA:
        while ((input[0] < '0' && input[0] > '1') || input[0] != 'q' || input[1] != '\0')
        {
            printf("Sorry, input again. : ");
            scanf("%s", input);
            if (input[0] == 'q' && input[1] == '\0')
            {
                return 0;
            }
            goto TEA_SCAN;
        }
    /* ////////////////////////////////////////////////////////////////// */

    /*  SELECT THE SIZE OF CUP;    */

    printf("Please select the size of your cup (enter 'q' to exit program): ");
    scanf("%s", input);
CUP_SCAN:
    if (input[1] != '\0')
    {
        input[0] = '\0';
        goto RE_SCAN_CUP;
    }

    if (input[0] == 'm' || input[0] == 'l' || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0')
        {
            return 0;
        }
        if (input[0] == 'l')
        {
            TOTAL_price += 10;
        }
    }
    else
    RE_SCAN_CUP:

        while ((input[0] != 'm' && input[0] != 'l' && input[0] != 'q') || input[1] != '\0')
        {
            printf("Sorry, input again. : ");
            scanf("%s", input);
            if (input[0] == 'q' && input[1] == '\0')
            {
                return 0;
            }
            goto CUP_SCAN;
        }

    /* ///////////////////////////////////////////////////////////////// */

    /* SELECT THE FLAVOuR */

    printf("Please select your flavour (enter 'q' to exit program): ");
    scanf("%s", input);
FLAVOUR_SCAN:
    if (input[1] != '\0')
    {
        input[0] = '\0';
        goto RE_SCAN_FLAVOUR;
    }
    else
    {
        if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
        {
            tempS = 5;
        }
        else
            tempS = 0;
    }

    input_temp = atoi(input) + (tempS - 5);

    if ((input_temp >= 0 && input_temp <= 4) || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0')
        {
            return 0;
        }
        //USE 'NEW_INTEGER' to position in the FLAVOR_PRICE_ARRAY;
        //ADD PRICE IN THE  "TOTAL_PRICE";
        //ASSIGN NEW_INTEGER to SELECTION_ARRAY
    }
    else

    RE_SCAN_FLAVOUR:
        while ((input[0] < '0' && input[0] > '9') || input[0] != 'q' || input[1] != '\0')
        {
            printf("Sorry, input again. : ");
            scanf("%s", input);
            if (input[0] == 'q' && input[1] == '\0')
            {
                return 0;
            }
            goto FLAVOUR_SCAN;
        }

    /* ///////////////////////////////////////////////////////////////// */

    /* SELECT TOPPING */

    printf("Please select your flavour (enter 'q' to exit program): ");
    scanf("%s", input);
TOPPING_SCAN:
    if (input[1] != '\0')
    {
        input[0] = '\0';
        goto RE_SCAN_TOPPING;
    }
    else
    {
        if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
        {
            tempS = 5;
        }
        else
            tempS = 0;
    }

    input_temp = atoi(input) + (tempS - 5);

    if ((input_temp >= 0 && input_temp <= 4) || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0')
        {
            return 0;
        }
        TOPPING_amount = input_temp;
        for (int i = 0; i < TOPPING_amount; i++)
        {
            /* CHOOSE TOPPING */
            printf("Select your %d topping : ", i + 1);
            scanf("%s", input);
        TOPPINGsel_SCAN:
            if (input[1] != '\0')
            {
                input[0] = '\0';
                goto RE_SCAN_TOPPINGsel;
            }
            else
            {
                if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
                {
                    tempS = 5;
                }
                else
                    tempS = 0;
            }

            input_temp = atoi(input) + (tempS - 5);

            if ((input_temp >= 0 && input_temp <= 4) || input[0] == 'q')
            {
                if (input[0] == 'q' && input[1] == '\0')
                {
                    return 0;
                }
                //USE 'NEW_INTEGER' to position in the FLAVOR_PRICE_ARRAY;
                //ADD PRICE IN THE  "TOTAL_PRICE";
                //ASSIGN NEW_INTEGER to SELECTION_ARRAY
            }
            else

            RE_SCAN_TOPPINGsel:
                while ((input[0] < '0' && input[0] > '9') || input[0] != 'q' || input[1] != '\0')
                {
                    printf("Sorry, input again. : ");
                    scanf("%s", input);
                    if (input[0] == 'q' && input[1] == '\0')
                    {
                        return 0;
                    }
                    goto TOPPINGsel_SCAN;
                }

        /* ///////////////////////////////////////////////////////////////////// */
        }
    }
    else

    RE_SCAN_TOPPING:
        while ((input[0] < '0' && input[0] > '9') || input[0] != 'q' || input[1] != '\0')
        {
            printf("Sorry, input again. : ");
            scanf("%s", input);
            if (input[0] == 'q' && input[1] == '\0')
            {
                return 0;
            }
            goto TOPPING_SCAN;
        }

    /* ///////////////////////////////////////////////////////////////// */
    printf("Total price is %d", TOTAL_price);

    return 0;
}