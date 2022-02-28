#include "HANGMAN_CODE.H"


void Print() {

   /*******
   Shows the instructions to the user
   Instructions on how to play the Hangman Game
   *********/

   printf("\t\t\t\t\tWelcome to the Hangman Game.\n"); //load();
   getch();
   clear;
   printf("Game instructions:\n");
   printf("\n-> The player must discover the word by guessing letters one at a time.\n\n->"
      " On each wrong guess, a body part is added to a picture of a hanged man. \n\n-> "
      "Player is allowed 5 mistakes, corresponding to hangman's head, body, left arm, right arm, left leg. At the 6th mistake the right leg is drawn, and the game is over. \n\n->"
      " If a letter is repeated more than once, the repeating occurrences are always considered as an error, even if the first time was correct.\n\n->"
      " Once the hanged man is complete, the player loses the game.\n");
   printf("\n\nPress any key to play game...");
   getch();
} //end if void Print

void load() {

   /******
   shows the loading animation
   *****/
   int r, q;
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t    loading...\n\n\n\n\t\t\t\t\t");
   for (r = 1; r <= 20; r++) {
      for (q = 0; q <= 100000000; q++); //to display the character slowly
      printf("%c", 219);
   }
   printf("\n\n\t\t\t\t(please press any key to continue)");
   getch();
} //end of void load

int introduction(char * answer) {

   /*****************
   This is the introduction of the game.
   It asks the user to enter a word to be guessed
   OR he/she will let the program choose for the
   words to be guessed.
   *****************/

   char answer1[100]; {
      printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\n");
      printf("#    #       *      # *    #    ########            #        #                 *         #*      #					    \n");
      printf("#    #      * *     #  *   #    #                  #  #    #   #              * *        #  *    #						\n");
      printf("#    #     *   *    #   *  #    #                 #   #   #      #           *   *       #   *   #			            \n");
      printf("######    * * * *   #    * #       #####         #      #         #         * * * *      #	*  #	            \n");
      printf("#    #    *     *   #     *#    #      #        #       #         #         *     *      #     * #				        \n");
      printf("#    #    *     *   #     *#    #      #       #        #         #         *     *      #      *#				        \n");
      printf("#    #    *     *   #      #    ########      #          #         #        *     *      #       #  		            \n");
      printf("\n\n     Welcome to the Hangman Game. \n-->This program was made by Asher <--\n        URL: asher\n");
   }

   //Ask the user for decision and save it to choice.
   int MainMenu = 777;
   while (MainMenu == 777) {
      int decide;
      printf("\nPress 1. Enter the Hangman Word (2 or more players).\nPress 2. Generate a random Hangman Word (You vs Computer).\nDecision: ");
      scanf("%d", & decide);
      getchar();
      if (decide == 1) goto choice1;
      else if (decide == 2) goto choice2;
      else printf("\nIncorrect Input: ");
      MainMenu = 777;
   }

   choice1: {

      printf("\n\nEnter the word to be guessed: ");
      scanf("%s", answer);
      printf("\nYour input: %s", answer);
      printf("\n\n(press any key to continue)");getch();clear;
      return *answer;
   }

   choice2: {

      randomizer;
      char words[e][8] = {
         "cat",
         "dog",
         "cow",
         "rainbow",
         "water",
         "apple",
         "love",
         "cotton",
         "camel",
         "cloud"
      };
      int f;
      f = rand() % 10;
      //  printf("This is the random word: %s", words[f]);
      printf("\nGenerated Successfully");
      strcpy(answer, words[f]);
      printf("\n\n(press any key to continue)");getch();clear;
      return *answer;
   }

} //end for int introduction (char *answer) function

void showHangman(int choice) {

   /***************
   This function show the hangman progress
   of being hanged after each wrong try
   ****************/

   switch (choice) {

   case 0:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    |                                              YOU LOSE THE GAME!");
      printf("\n\t||   / %c", '\\');
      printf("\n\t||      ");
      break;
   case 1:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    | ");
      printf("\n\t||     %c", '\\');
      printf("\n\t||      ");
      break;
   case 2:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    | ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 3:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 4:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO ", '\\');
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 5:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||    O ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   } //end of switch-case
   return;
} //end of showhangman

void planeFig(void) {

   /*show the HANGMAN*/

   printf("\n\n\n");
   printf("\tH A N G M A N");
   printf("\n\t+------+");
   printf("\n\t|      | ");
   printf("\n\t|        ");
   printf("\n\t|        ");
   printf("\n\t|        ");
   printf("\n\t|       ");
   printf("\n\t========\n\n\n");
} 
