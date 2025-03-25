# 1a1b Number Guessing Game

## Overview
This is the first game I developed using **C++ in a Linux Ubuntu environment**!  

<br>

**1a1b** is a two-player number guessing game where players try to guess each other’s 4-digit secret number. The game provides hints after each guess using 'a' and 'b':

- **'a'** indicates that both the number and its position are correct.
- **'b'** indicates that the number is correct but in the wrong position.

<br>

Players continue guessing until one correctly identifies the opponent’s number.

## How to Play
1. The game starts with a **"1a1b" background screen**.
   
![image](https://github.com/user-attachments/assets/4841af3e-2bb6-44a3-8de1-f1a5f6a2a5cf)

2. Each player enters their **name** and **4-digit secret number**.

![image](https://github.com/user-attachments/assets/7e62401b-ab5e-4851-83d8-d35fd91308e3)

3. Players take turns guessing the opponent's number.
4. After each guess, the program provides hints:
   - **Example:**  
     - Jacob’s secret number: **1234**  
     - Vernessa’s secret number: **5678**

   **Turn 1**
     - Jacob guesses **8765** → **0a 4b** (all digits correct but misplaced)  
     - Vernessa guesses **1256** → **2a 0b** (two digits correct in the right place)
    
   **Turn 2**
     - Jacob guesses **5679** → **3a 0b** (three digits correct in the right place)  
     - Vernessa guesses **5687** → **0a 0b** (all numbers incorrect)
  
       ![image](https://github.com/user-attachments/assets/7dce367a-df13-49b5-8c42-66748664f3f3)
      
6. The game continues until a player guesses the correct number.

  ![image](https://github.com/user-attachments/assets/c465ae76-c2a3-487b-a0c3-e684b32f8260)

7. The program asks if players want to **restart the game** or **exit**.

<br>

## Features
- **Two-player mode** with interactive turn-based gameplay.
- **Hint system** to guide players toward the correct number.
- **Replay option** after each round.

<br>

## Installation & Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/Jacobshin04/1a1b-Number-Guessing-Game.git
   cd 1a1b-Number-Guessing-Game
Compile the program using g++:

g++ 1a1b.cpp -o 1a1b

Run the game:

./1a1b

<br>

## Future Improvements
Implementing a single-player mode with an AI opponent.

Adding a score-tracking system to track wins and losses.

Introducing customizable number lengths (e.g., 3-digit or 5-digit mode).

Have fun playing 1a1b and challenge your friends! 🎮



Let me know if you’d like any changes! 🚀
