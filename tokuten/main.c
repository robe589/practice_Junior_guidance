#include<stdio.h>

struct Human
{
	char name[50];//名前
	int score[5];//5教科の得点
};

struct Analysis_data
{
	int max_score;
	int min_score;
	double average_score;
};

//教科番号用定数
enum subject
{
	JAPAN_LANGUAGE,
	MATHEMATICS,
	SOCIETY,
	ENGLISH_LANGUAGE,
	SCIENCE,
};

//プロトタイプ宣言
void read_score_from_file(struct Human *human);
void analysis_score_each_personal(struct Human *human,struct Analysis_data *analysis_data);
void analysis_score_each_subject(struct Human *human,struct Analysis_data *analysis_data);
int find_max_score(int *);
int find_min_score(int *);
double find_average_score(int *);
void show_human_info(struct Human *human);
void show_analysis_data(struct Analysis_data *analysis_data);

int main()
{
	struct Human human[5];//5人分の点数を格納
	struct Analysis_data analysis_personal_data[5];
	struct Analysis_data analysis_subject_data[5];

	//ファイルから得点を取得して、構造体に格納
	read_score_from_file(human);
	show_human_info(human);
	//個人ごとの5教科の平均点、最大得点、最小得点を求める
	analysis_score_each_personal(human,analysis_personal_data);
	show_analysis_data(analysis_personal_data);
	//教科ごとの5教科の平均点、最大得点、最小得点を求める
	analysis_score_each_subject(human,analysis_subject_data);

	return 0;
}

void read_score_from_file(struct Human *human)
{
	FILE *fp;
	struct Human *ph;
	int i,ret;
	char str[255];

	fp=fopen("data.csv","r");
	if(fp==NULL){
		printf("ファイルが開けません\n");
		return;
	}

	for(i=0;i<5;i++){
		//
		if(i==0){
			fscanf(fp,"%s",str);
		}
		ph=&human[i];
		ret=fscanf(fp,"%[^,],%d,%d,%d,%d,%d",ph->name,&(ph->score[0]),&(ph->score[1]),&(ph->score[2]),&(ph->score[3]),&(ph->score[4]));
	}
	fclose(fp);

	return;
}

void show_human_info(struct Human *human)
{
	int i;
	struct Human *ph;

	for(i=0;i<5;i++){
		ph=&human[i];
	printf("name=%s,%d,%d,%d,%d,%d\n",ph->name,ph->score[0],ph->score[1],ph->score[2],ph->score[3],ph->score[4]);
	}
}

void analysis_score_each_personal(struct Human *human,struct Analysis_data *analysis_data)
{
	int max_score,min_score;
	double average_score;
	int i;

	for(i=0;i<5;i++){
		max_score=find_max_score(human[i].score);
		min_score=find_min_score(human[i].score);
		average_score=find_average_score(human[i].score);
		analysis_data[i].max_score=max_score;
		analysis_data[i].min_score=min_score;
		analysis_data[i].average_score=average_score;
	}

	return;
}

void show_analysis_data(struct Analysis_data *analysis_data)
{
	int i;
	struct Analysis_data *pa;

	for(i=0;i<5;i++){
		pa=&analysis_data[i];
		printf("i=%d,max=%d,min=%d,average=%.1f\n",i,pa->max_score,pa->min_score,pa->average_score);
	}
}

int find_max_score(int *score)
{
	int max=score[0],i;

	for(i=0;i<5;i++){
		if(score[i]>max){
			max=score[i];
		}
	}

	return max;
}
int find_min_score(int *score)
{
	int min=score[0],i;

	for(i=0;i<5;i++){
		if(score[i]<min){
			min=score[i];
		}
	}

	return min;
}

double find_average_score(int *score)
{
	double average=0;
	int i;

	for(i=0;i<5;i++){
		average+=score[i];
	}
	average/=5;

	return average;
}

void analysis_score_each_subject(struct Human *human,struct Analysis_data *analysis_data)
{

	return;
}

