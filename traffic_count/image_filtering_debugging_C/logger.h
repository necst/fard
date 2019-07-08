#ifndef LOGGER_HPP
#define LOGGER_HPP

#define LOG 1 //1 -> active; 0 -> unactive
//to improve with different levels (output, debugging, priority, etc...)

void logInt (int toPrint)
{
	if (LOG == 1) {
		printf ("%d\n", toPrint);
	}
}

void logString (char *toPrint)
{
	if (LOG == 1) {
		printf ("%s\n", toPrint);
	}
}