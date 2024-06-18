#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
#include <thread>

void eraseLines(int count) {
	if (count > 0) {
		std::cout << "\x1b[2K";
		for (int i = 1; i < count; i++) {
			std::cout
				<< "\x1b[1A"
				<< "\x1b[2K";
		}
		std::cout << "\r";
	}
}

int main()
{
	srand((unsigned)time(0));
	std::string input;
	std::cout << "Welcome to the 'Rock Paper Scissor' game!\nplease type the name of the item you want to play\nThen 'exit' when you're done!\n";
	while (input != "exit")
	{
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), towlower);

		int tool;
		bool allowRollTool;

		if (input == "rock")
		{
			tool = 1;
			allowRollTool = true;
		}

		else if (input == "paper")
		{
			tool = 2;
			allowRollTool = true;
		}

		else if (input == "scissor")
		{
			tool = 3;
			allowRollTool = true;
		}

		else if (input == "exit")
		{
			break;
		}

		else
		{
			std::cout << "That's not a valid tool!\n";
			allowRollTool = false;
		}
		
		int rollForTool;
		if (allowRollTool == true)
		{
			rollForTool = (rand() % 3) + 1;

			if (rollForTool == 1) //system rolls for rock
			{
				std::cout << "System: Rock\n";
			}

			else if (rollForTool == 2) //system rolls for paper
			{
				std::cout << "System: Paper\n";
			}

			else if (rollForTool == 3) //system rolls for scissor
			{
				std::cout << "System: Scissor\n";
			}

			switch (tool)
			{
			case 1: //rock 
				if (rollForTool == 1) //system rolls for rock
				{
					std::cout << "That's a draw!\n";
				}

				else if (rollForTool == 2) //system rolls for paper
				{
					std::cout << "You lose!\n";
				}

				else if (rollForTool == 3) //system rolls for scissor
				{
					std::cout << "You win!\n";
				}
				break;

			case 2: //paper
				if (rollForTool == 1) //system rolls for rock
				{
					std::cout << "You win!\n";
				}

				else if (rollForTool == 2) //system rolls for paper
				{
					std::cout << "That's a draw!\n";
				}

				else if (rollForTool == 3) //system rolls for scissor
				{
					std::cout << "You lose!\n";
				}
				break;

			case 3: //scissor
				if (rollForTool == 1) //system rolls for rock
				{
					std::cout << "You lose!\n";
				}

				else if (rollForTool == 2) //system rolls for paper
				{
					std::cout << "You win!\n";
				}

				else if (rollForTool == 3) //system rolls for scissor
				{
					std::cout << "That's a draw!\n";
				}
				break;
			}
			std::this_thread::sleep_for(std::chrono::seconds(2));
			eraseLines(4);
		}

		if (allowRollTool == false)
		{
			std::this_thread::sleep_for(std::chrono::seconds(2));
			eraseLines(3);
		}

		allowRollTool = true;
	}
}