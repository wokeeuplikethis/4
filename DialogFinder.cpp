#include "DialogFinder.h"

void DialogFinder::FindDialogs()
{
	std::string tempDialog;
	bool isDialog = false;
	for (int i = 1; i < text.size(); i++)
	{	
		char dash = '—';
		if (text[i] == dash && text[i - 1] == '\n')
			isDialog = true;
		else false;

			if (isDialog)
				tempDialog += text[i];

			if (text[i] == '\n' && (text[i - 1] == '!' || text[i - 1] == '.' || text[i - 1] == '?'))
			{
				isDialog = false;
				if (tempDialog != "") {
					dialogs.push_back(tempDialog);
				}
				tempDialog.clear();
			}
	}
	/*if(isDialog)
		dialogs.push_back(tempDialog);*/
	
}

std::string DialogFinder::GetDialog(int number)
{
	if (number > dialogs.size())
		return "";

	return dialogs[number];
}

std::vector<std::string> DialogFinder::GetVector()
{
	return dialogs;
}

int DialogFinder::GetCountOfDialogs()
{
	return static_cast<int>(dialogs.size());
}

