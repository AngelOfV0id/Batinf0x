/* See unlicense.txt for licensing details. */

#include <stdio.h>
#include <windows.h>

#define NAME		"Batinf0x"
#define AUTHOR		"AngelOfV0id, 2024"
#define HOMEPAGE	"https://github.com/AngelOfV0id/Batinf0x"

#define UNKNOWN		255

#define HOURS(TIME)		(TIME / 3600)
#define MINUTES(TIME)	(TIME % 3600 / 60)
#define SECONDS(TIME)	(TIME % 60)

void main(int argc, char** argv)
{
	if (argc == 2)
	{
		if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version"))
		{
			printf("%s %s by %s\n%s\n", NAME, VERSION, AUTHOR, HOMEPAGE);
			return;
		};
	};
	
	SYSTEM_POWER_STATUS	status;
	GetSystemPowerStatus(&status);
	
	int	ac = status.ACLineStatus,
		flag = status.BatteryFlag,
		percent = status.BatteryLifePercent,
		time = status.BatteryLifeTime,
		fulltime = status.BatteryFullLifeTime;

	if (ac != UNKNOWN)
		printf("AC power: %s.\n", (ac == 1 ? "online" : "offline"));

	if (flag != UNKNOWN)
	{
		switch (flag)
		{
			case 128:
				printf("No system battery.\n");
				break;
			case 1:
			case 2:
			case 4:
			case 8:
			case 9:
				printf("Battery is %scharging.\n", (flag == 8 || flag == 9 ? "" : "dis"));
				break;
		};
	};
	
	if (percent != UNKNOWN)
	{
		printf("Battery life: %d%%", percent);
		if (flag != 8 && flag != 9)
			printf(" - %s",
				(flag == 1 ? "high" : (flag == 2 ? "low" : (flag == 4 ? "critical" : ""))));
		printf(".\n");
	};

	if (time != -1)
		printf("Battery life time: %02d:%02d:%02d.\n",
			HOURS(time), MINUTES(time), SECONDS(time));

	if (fulltime != -1)
		printf("Battery full life time: %02d:%02d:%02d.\n",
			HOURS(fulltime), MINUTES(fulltime), SECONDS(fulltime));
}