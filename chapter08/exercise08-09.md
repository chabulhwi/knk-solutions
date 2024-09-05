# Chapter 8, Exercises 8-9

## Exercise 8

```c
double temperature_readings[30][24];
```

## Exercise 9

```c
double temperature_sum = .0, temperature_average;

for (int day = 0; day < 30; day++) {
	for (int hour = 0; hour < 24; hour++) {
		temperature_sum += temperature_readings[day][hour];
	}
}

temperature_average = temperature_sum / (30 * 24);
```
