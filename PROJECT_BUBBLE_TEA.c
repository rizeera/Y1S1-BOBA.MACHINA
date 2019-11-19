#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[10];
int input_temp;
int tempS;
int STRlength;
int valid_check;

    

    /* INPUT / OUTPUT */ 
    int TOPPING_amount; 
    

    /* REFILLING THE MACHINE */
    int TEA_price[6] = { 30,30,30,45,40,35 }; //base on Medium cup size's price
    int FLAVOR_price[4] = { 0,5,5,10 }; 
    int TOPPING_price[4] = { 5,15,10,10 }; 
    int TOPPING_unit[4] = { 2,0,0,0 };  //OR JUST FILL THE VALUE LATER;

    /* MONEY ARRAY */
     int MONEY_value[5] = { 100,50,20,10,5 };
    int MONEY_machine[5] = { 0,4,0,1,2 }; 
    int MONEY_insert[5]; 
    int MONEY_changes[5];
    
    /* MONEY */
    int TOTAL_insert = 0;
    int TOTAL_change = 0;
    int TOTAL_price = 0; 
    int TOTAL_machine_money = 0;

/*
                                                                                            /////
    int SELECTION_ARRAY[] = { (TEA_input) , (FLAVOR_input) , (TOPPING_1ST) , (TOPPING_2ND)};///// MAY NOT NEED IT
                                                                                            ///// COULD USE NEW FUNCTION TO PRINT SELECTED MENU //////////
                                                                                           
*/

int main()
{
    /* MAIN MENU */

    printf("         _________________________________  \n") ;
    printf("---------|Welcome to Bubble Tea Cafe : -)|-------- \n") ;
    printf("---------|_______________________________|-------- \n") ;
    printf("  ....                                            \n") ;
    printf("  |  |                                    (o)(o) \n") ;
    printf(":------:                                 /     \\ \n") ;
    printf("|======|                                /       | \n") ;
    printf("|      |                               /   \\  * | \n") ;
    printf("|--Bo--|                 ________     /    /\\__/ \n") ;
    printf("|--Ba--|                /        \\   /    / \n") ;
    printf("|      |       / \\     /  ____    \\_/    / \n") ;
    printf("|o8oo8o|      // \\ \\  /  /    \\         / \n") ;
    printf("|88o88o|      V   \\ \\/  /      \\       / \n") ;
    printf("'------'           \\___/        \\_____/ \n") ;
    printf("-------------------------------------------------- \n") ;
    printf("\n") ;
    printf("Menu                                 M      L        \n") ;
    printf("\n") ;
    printf("0:Black tea                          30     40     \n") ;
    printf("1:Green tea                          30     40     \n") ;
    printf("2:Thai tea                           30     40     \n") ;
    printf("3:Passion fruit green tea            45     55     \n") ;
    printf("4:Taro smoothie tea                  40     50     \n") ;
    printf("5:Peach tea                          35     45     \n") ; 
    printf("\n") ;
    printf("Flavors \n") ;
    printf("\n") ;
    printf("0:Black tea                          +0 \n") ;
    printf("1:Green tea                          +5 \n") ;
    printf("2:Thai tea                           +5 \n") ;
    printf("3:Passion fruit green tea            +10 \n") ; 
    printf("\n") ;
    printf("Toppings \n") ;
    printf("\n") ;
    printf("0:Black tea                          +5  (%d units left)  \n",TOPPING_unit[0] /*Put unit here naja*/) ;
    printf("1:Green tea                          +15 (%d units left)  \n",TOPPING_unit[1] /*Put unit here naja*/) ;
    printf("2:Thai tea                           +10 (%d units left)  \n",TOPPING_unit[2] /*Put unit here naja*/) ;
    printf("3:Passion fruit green tea            +10 (%d units left)  \n",TOPPING_unit[3] /*Put unit here naja*/) ;

    ////////////////////////////////////
    ////////* ASK FOR BASSE TEA *///////
    ////////////////////////////////////

    printf("Please select your base tea (enter 'q' to exit program): ");
    scanf("%s", input);
TEA_SCAN:
    if (input[1] != '\0') { input[0] = '\0'; goto RE_SCAN_TEA;  }
    else
    {
        if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
        {
            tempS = 5;
        } else tempS = 0;
    }

    input_temp = atoi(input) + (tempS - 5);

    if ((input_temp >= 0 && input_temp <= 5) || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0') { return 0; }
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
            if (input[0] == 'q' && input[1] == '\0') { return 0; }
            goto TEA_SCAN;
        }
    /* ////////////////////////////////////////////////////////////////// */

    /////////////////////////////////////////////
    ///////*  SELECT THE SIZE OF CUP;    *///////
    /////////////////////////////////////////////

    printf("Please select the size of your cup (enter 'q' to exit program): ");
    scanf("%s", input);
CUP_SCAN:
    if (input[1] != '\0') { input[0] = '\0'; goto RE_SCAN_CUP; }

    if (input[0] == 'm' || input[0] == 'l' || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0') { return 0; }
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
            if (input[0] == 'q' && input[1] == '\0') { return 0; }
            goto CUP_SCAN;
        }

    /* ///////////////////////////////////////////////////////////////// */

    //////////////////////////////////////
    ////////* SELECT THE FLAVOuR *////////
    //////////////////////////////////////

    printf("Please select your flavour (enter 'q' to exit program): ");
    scanf("%s", input);
FLAVOUR_SCAN:
    if (input[1] != '\0') { input[0] = '\0'; goto RE_SCAN_FLAVOUR; }
    else
    {
        if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
        { tempS = 5; } 
        else tempS = 0;
    }

    input_temp = atoi(input) + (tempS - 5);

    if ((input_temp >= 0 && input_temp <= 3) || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0') { return 0; }
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
            if (input[0] == 'q' && input[1] == '\0') { return 0; }
            goto FLAVOUR_SCAN;
        }

    /* ///////////////////////////////////////////////////////////////// */

    //////////////////////////////////////
    /////////* SELECT TOPPING *///////////
    //////////////////////////////////////

    printf("Please select your topping (maximum of 2) (enter 'q' to exit program): ");
    scanf("%s", input);
TOPPING_SCAN:
    if (input[1] != '\0'){ input[0] = '\0'; goto RE_SCAN_TOPPING; }
    else
    {
        if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
        { tempS = 5; }
        else tempS = 0;
    }

    input_temp = atoi(input) + (tempS - 5);

    if ((input_temp >= 0 && input_temp <= 2) || input[0] == 'q')
    {
        if (input[0] == 'q' && input[1] == '\0') { return 0; }
        TOPPING_amount = input_temp;

        for (int i = 0; i < TOPPING_amount; i++)
        {

            ///////////////////////////////////////////
            ////////////* CHOOSE TOPPING */////////////
            ///////////////////////////////////////////
            printf("Select your %d topping : ", i + 1);
            scanf("%s", input);
        TOPPINGsel_SCAN:
            if (input[1] != '\0') { input[0] = '\0'; goto RE_SCAN_TOPPINGsel; }
            else
            {
                if (input[0] >= '0' && input[0] <= '9' || input[0] == 'q')
                { tempS = 5; }
                else tempS = 0;
            }

            input_temp = atoi(input) + (tempS - 5);

            if ((input_temp >= 0 && input_temp <= 3) || input[0] == 'q')
            {
                if (input[0] == 'q' && input[1] == '\0') { return 0; }
                if (TOPPING_unit[input_temp] > 0)
                {
                    //ADD TOPPING;
                    TOTAL_price += TOPPING_price[input_temp];
                    TOPPING_unit[input_temp]--;
                }
                else
                {
                    printf("Topping is out of stock, enter again :");
                    scanf("%s", input);
                    if (input[0] == 'q' && input[1] == '\0') { return 0; }
                    goto TOPPINGsel_SCAN;
                }
            }
            else

            RE_SCAN_TOPPINGsel:
                while ((input[0] < '0' && input[0] > '9') || input[0] != 'q' || input[1] != '\0')
                {
                    printf("Sorry, input again. : ");
                    scanf("%s", input);
                    if (input[0] == 'q' && input[1] == '\0') { return 0; }
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
            if (input[0] == 'q' && input[1] == '\0') { return 0; }
            goto TOPPING_SCAN;
        }

    /* ///////////////////////////////////////////////////////////////// */

    ////////////////////////////////////////////////
    ///////// /* ARE YOU READY TO PAY ? */ /////////
    ////////////////////////////////////////////////
    printf("Total price is %d", TOTAL_price);
    printf("Are YOu ReaDY TO PaY nOw ? (y/n):");
    scanf("%s", input);
MONEY_SCAN:
    if (input[1] != '\0') { input[0] = '\0'; goto RE_SCAN_MONEY; }
    else
    {
        if (input[0] == 'n') { return 0; }
        else if (input[0] != 'y')
        {
            goto RE_SCAN_MONEY;
        }
    }
    RE_SCAN_MONEY:
    while (input[0]!='n' && input[0]!='y' && input[1]!='\n')
    {
        printf("sorry, input again");
        scanf("%s", input);
        goto MONEY_SCAN;
    }

    ///////////////////////////////////////////////////////


    //////////////////////////////////////////
    ////// /* INSERT AMOUNT OF MONEY *////////
    //////////////////////////////////////////
    printf("Machine cash: ( ");
    for (int i = 0; i < 5; i++)
    {
        if (i==4)   
            printf("%d=%d) \n" ,MONEY_value[i] ,MONEY_machine[i]);
        else  
            printf("%d=%d,", MONEY_value[i], MONEY_machine[i]);
    }

        /* INSERT AMOUNT PART */
    for (int i = 0; i < 5; i++)
    {
        printf("%d=:" ,MONEY_value[i]);
        scanf("%s" ,input);

CHECK_VALID:
        STRlength = strlen(input);
        for (int i = 0; i < STRlength; i++)
        {
            if (input[i] < '0' || input[i] > '9') { valid_check = 0; break;}
            else { valid_check = 1; }
        }

        RE_SCAN_AMT:
        if (valid_check==0)
        {
            printf("invalid, input again:");
            scanf("%s" ,input);
            goto CHECK_VALID;
        }

        input_temp = atoi(input);
        MONEY_insert[i] = input_temp;
        MONEY_machine[i] += input_temp;
    }
        
    ///////////////////////////////////////////////
    
    printf("machine money:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d " ,MONEY_machine[i]);
    }
    printf("\n");
    printf("money insert :");
    for (int i = 0; i < 5; i++)
    {
        printf("%d " ,MONEY_insert[i]);
    }
    
    

    ///////////////////////////////////////////
    ////////* CALCULATING FOR CHANGEs *////////
    ///////////////////////////////////////////

    for (int i = 0; i < 5; i++)
    {
        //TOTAL_insert += (MONEY_value[i]*MONEY_insert[i]); ใช้ทำบ้าอะไรฟระ 
        TOTAL_machine_money += (MONEY_value[i]*MONEY_machine[i]);
    }

    if (TOTAL_price == TOTAL_machine_money)
    {
        /* CASE WHERE TOTAL_price equal to TOTAL SUM OF MONEY IN THE MACHINE */
        for (int i = 0; i < 5; i++)
        {
            MONEY_changes[i] = MONEY_machine[i];
            MONEY_machine[i] = 0;
        }
        
    }
    else if (TOTAL_price > TOTAL_machine_money)
    {
        /* CASE WHERE MACHINE DOESN"T HAVE ENOUGH MONEY */
    }
    else
    {
        /* NORMAL CASE */
    }
    
    

    
    



    


    

    return 0;
}