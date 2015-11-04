int findlength(char *dob)
{
	int count = 0;
	while (dob[count] != '\0')
	{
		count++;
	}
	return count;
}



int equivalentinteger(char inputarray[], int j, int i)
{
	int index = 0, equivalentint = 0;

	for (index = j; index <= i; index++)
	{

		equivalentint = equivalentint * 10 + inputarray[index] - '0';
	}

	return equivalentint;
}

int checkleapyear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0;

}



int checkforvalidity(int date, int month, int year)
{
	if (month > 12 || month <= 0||date>31||date<=0)
	{
		return 0;

	}
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12 : 
			return 1;
			break;
		case 2:
			if (checkleapyear(year))
			{
				if (date <= 29)
				{
					return 1;
				}
				else return 0;

			}
			else
			{
				if (date <= 28)
				{
					return 1;
				}
				else return  0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date <= 30)
			{
				return 1;

			}
			else
			{
				return 0;
			}
			break;

		}


	}

	return 0;

}




int evaluate(char *dob,int *date,int *month,int *year)
{
	int i, j = 0, slashcharacter = 0,valid;
	for (i = 0; dob[i] != '\0'; i++)
	{
		if (dob[i] == '-')
		{

			slashcharacter++;
			switch (slashcharacter)
			{
			case 1:
				*date = equivalentinteger(dob, j, i - 1);
				j = i + 1;
				break;


			case 2:
				*month = equivalentinteger(dob, j, i - 1);
				j = i + 1;
				*year = equivalentinteger(dob, j, findlength(dob) - 1);
				break;

			}


		}
	}
	valid = checkforvalidity(*date, *month, *year);
	return valid;
}





       


int isOlder(char *dob1, char *dob2) {
	int len1 = findlength(dob1); int len2 = findlength(dob2); int valid1, valid2, date1 = 0, month1 = 0, year1 = 0, date2 = 0, month2 = 0, year2 = 0; 
	if (len1 != len2)
	{
		return -1;
	}
	else {
		valid1 = evaluate(dob1, &date1, &month1, &year1); valid2 = evaluate(dob2, &date2, &month2, &year2);


		if (valid1 == 0 || valid2 == 0)
		{
			return -1;
		}
		else
		{
			if (date1 == date2&&month1 == month2&&year1 == year2)
			{
				return 0;
			}
			else

			{

				return year1<year2 ? 1 : (year1>year2) ? 2 : (month1<month2) ? 1 : (month1>month2) ? 2 : (date1<date2) ? 1 : 2;
			}
		}
	}


	return 0;
}


