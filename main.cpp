#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void sortNames(vector<string>& FriendsNames);

bool CurrentNameIsShorter(string A, string B);

int main()
{
	ifstream Friends("NameDatabase.txt");
	string temp;
	string garbage;
	vector<string> FriendsNames;

	if (Friends.fail())
	{
		cout << "NameDatabase.txt failed to open!\n";
	}
	else
	{
		//Get Data
		while (!Friends.eof())
		{
			Friends >> temp;
			getline(Friends, garbage);
			FriendsNames.push_back(temp);
		}

		cout << "Before - \n";
		for (int i = 0; i < FriendsNames.size(); i++)
		{
			cout << FriendsNames[i] << endl;
		}
		cout << "\n";

		//Sort
		sortNames(FriendsNames);


		//Output
		cout << "After - \n";
		for (int i = 0; i < FriendsNames.size(); i++)
		{
			cout << FriendsNames[i] << endl;
		}
	}
	system("pause");
	return 0;
}

void sortNames(vector<string>& FriendsNames)
{
	string currentName;
	string nextName;
	string temp;
	int max;
	int currIndex = 0;

	char CurrChar;
	char NextChar;

	for (int a = 0; a < FriendsNames.size() - 1; a++)//Compare every name
	{
				for (int i = 0; i < FriendsNames.size() - 1; i++)//Compare every Name
				{
							currentName = FriendsNames[i];//Set current name
							nextName = FriendsNames[i + 1];//Set next name


							if (CurrentNameIsShorter(currentName, nextName))//See how many characters we need to compare worst case
							{
								max = currentName.length();
							}
							else
							{
								max = nextName.length();
							}

							while (currIndex < max)//Loop through each character index
							{

								if (currentName[currIndex] > nextName[currIndex])//B - A
								{
									temp = FriendsNames[i];
									FriendsNames[i] = FriendsNames[i + 1];
									FriendsNames[i + 1] = temp;
									break;
								}
								else if (currentName[currIndex] == nextName[currIndex])//A - A
								{
									currIndex++;
								}
								else// A - B
								{
									break;//Should break while loop --> move on to next index comparison
								}
							}
							currIndex = 0;
				}
	}
}

bool CurrentNameIsShorter(string A, string B)
{
	if (A.length() < B.length())
		return 1;
	else
		return 0;
}