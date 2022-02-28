#include "HANGMAN_CODE.H"
//Main-Body
int main() {
   /****
   Declarations
   ****/
   THE_ALL_REPEATER_SHORTCUT: {
      printf("\n");
   }
   char answer[100], //answer refers to the hangmanword.
   guess = '\0', //declare guess as a character of terminating character, so that guess will not cause an undefined behavior.
   missed[100]; //missed refers to characters that are inputted by the user, but not in the hangman word
   int x = 0,
   limit = 1,
   wrongTry = 6, //refers to 5 chances by the user to guess the hangman word.
   length; //length of the string 'answer' or the hangman word
   char char_seen[length]; //declare the size of char_seen. AND. look up for repeated input by the user
   int i,
   gameover = 0; //gameover initialize to 0 so that when 0 then stop the execution otherwise comtinue running the program.
   int rewinder = 1, //rewinder set value to 1 so that the program will run, if rewinder doesn't have value of 1, then the entire program will collapse.
   r = 0;

   //Hangman Game Program
   while (rewinder == 1) {
      wrongTry = 6;
      introduction(answer);
      length = strlen(answer); // What is the size of the string answer?
      for (i = 0; i < length; i++) //Initialize all mask value to 0.
      {
         char_seen[i] = 0;
      }
      Print();
      clear;
      load();
      clear;
      planeFig();

      printf("Missed Letters:");
      while (!gameover) {
         // Print word with '_' for unguessed letters
         printf("\nMystery Word : ");
         int j;
         for (j = 0; j < length; ++j) {
            if (char_seen[j]) {
               printf("%c", answer[j]); //substituter  for the guess letters
            } else {
               printf("_ "); //putter for the unguess letters.
            }
         }
         printf("\n");

         // Take the player's next guess
         char guess;
         printf("Guess a Letter. \n");
         scanf(" %c", & guess);

         //duplicate stopper
         for (x = 0; x < limit; x++) {
            if (guess == missed[x]) {
               printf("You have already guess that letter. Choose again. (press any Enter to Guess Again. ) \n");
               getch();
            }
         }

         //If there is a guess correct-identifer
         int l, match = 0;
         for (l = 0; l < length; ++l)
            if (guess == answer[l]) //if there is a match
         {
            match = 1;
            break;
         }

         //if there is no match
         if (match == 0) {
            printf("\nMissed Letters: ");
            missed[x] = guess;
            for (r = 0; r < limit; r++)
               printf(" %c", missed[r]);
            x++;
            limit++;
            --wrongTry;
            showHangman(wrongTry);
            printf("\nMissed Letters: ");
            for (r = 0; r < limit; r++)
               printf(" %c", missed[r]);
         }

         //if there is a match but is repeated
         if (match == 1) {
            int k;
            for (k = 0; k < length; k++) {
               if (answer[k] == guess) {
                  if (char_seen[k]) //if true
                  {
                     missed[x] = guess;
                     for (r = 0; r < limit; r++)
                        printf(" %c", missed[r]);
                     x++;
                     limit++;
                     --wrongTry;
                     showHangman(wrongTry);
                     printf("\nMissed Letters: ");
                     for (r = 0; r < limit; r++)
                        printf(" %c", missed[r]);
                  }
                  char_seen[k] = 1;
               }
            }
         }

         //Verify char_seen if all is filled up.
         int sea = 0;
         gameover = 1;
         for (sea = 0; sea < length; sea++) {
            if (!char_seen[sea]) {
               gameover = 0;
               break;
            }
         }

         //Stop if wrong try reaches limit , or reaches 0.
         if (wrongTry == 0) {
            gameover = 0;
            break;
         }

      } //stop the greatwhile if gameover reaches 0.

      //Results of the Game.
      if (wrongTry == 0) {
         printf("\n\nYou lost! The secret word is \"%s\"!\n", answer);
      }

      if (wrongTry > 0) {
         printf("\n\nYes! The secret word is \"%s\"! You have won!\n", answer);
      }
      int battery = 1; //battery for incorrect input
      while (battery == 1) {
         printf("Do you want to play again? (yes or no)\n");
         char say[3];
         scanf("%s", say);
         if (strcmp(say, "yes") == 0) {
            rewinder = 0;
            battery = 0;
            clear;
            goto THE_ALL_REPEATER_SHORTCUT;
         } //if yes then repeat hangman game program since rewinder =1 and battery 0.
         else if (strcmp(say, "no") == 0) {
            rewinder = 0;
            battery = 0;
         } // if no then stop the program.
         else battery = 1;
      } // end of while

   } //The greatest While	or the Hangman Program Game or while (rewinder)
   return 0;
} //Main Body

