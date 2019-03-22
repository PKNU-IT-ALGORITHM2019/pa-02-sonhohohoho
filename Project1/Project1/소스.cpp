#include<stdio.h>
#include<math.h>


typedef struct point {
	double x;
	double y;
}point;
point p[100];
point s[100];

double min = -1;

int N;

bool check(int nood);
double func(double len, int nood);


int main(void) {

	errno_t err;
	FILE *fp;




	err = fopen_s(&fp, "input0.txt", "r");
	if (err == 0)
		puts("파일오픈 성공(기다려 주세요)\n");
	else
		puts("파일 오픈 실패\n");

	fscanf_s(fp, "%d", &N);

	for (int i = 0; i < N; i++) {
		fscanf_s(fp, "\n%lf %lf", &p[i].x, &p[i].y);
	}

	fclose(fp);

	printf("최단거리 %lf", func(0, 0));

	return 0;
}

bool check(int nood) {

	for (int i = 0; i < nood; i++) {
		if (s[nood].x == s[i].x&&s[nood].y == s[i].y)
			return false;

	}
	return true;
}

double func(double len, int nood) {

	double dis;
	double tm[100];
	double emp;


	if (!check(nood - 1) || (min != -1 && min < len)) {

		return 0;

	}

	else if (nood == N) {

		return len + sqrt((s[N - 1].x - s[0].x)*(s[N - 1].x - s[0].x) + (s[N - 1].y - s[0].y)*(s[N - 1].y - s[0].y));

	}

	else {

		for (int i = 0; i < N; i++) {

			if (nood == 0) {
				s[nood].x = p[i].x;
				s[nood].y = p[i].y;



				dis = 0;
			}
			else {

				s[nood].x = p[i].x;
				s[nood].y = p[i].y;


				dis = sqrt((s[nood - 1].x - p[i].x)*(s[nood - 1].x - p[i].x) + (s[nood - 1].y - p[i].y)*(s[nood - 1].y - p[i].y));

			}

			tm[i] = func(len + dis, nood + 1);

		}


		emp = 100000;


		for (int i = 0; i < N; i++) {
			if (tm[i] != 0 && tm[i] < emp) {
				emp = tm[i];
			}
		}

		if (emp == 100000)return 0;


		if (nood == (N - 1) && (min == -1 || min > emp))
			min = emp;



		return emp;

	}

}