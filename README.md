# Burger_Eating_Game_AI_Lab

Eating Burger is an AI based game and this game is implementated using Dynamic Programing. There are 2 players (one player is Human and 
other is Computer). Games Rules are described in the pptx file.


Here is the dp equation:

1. dp[i] = max( dp[i+1] , burger[i] + postSum - dp[i+1] );


using this equation, we can calculate the optimal solution for AI to win the game.
