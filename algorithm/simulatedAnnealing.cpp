#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

int num, cap, wei[1010], price[1010];
string dir;

double randomnumber(double x, double y){
    static default_random_engine generator;
    uniform_real_distribution<double> unif(x, y);
    return unif(generator);
}

void takeit(int a[], int b[]){
    for(int i = 0; i < num; i++)
        a[i] = b[i];
}

int cal(int a[], int b[]){
    int x = 0, y = 0;
    int w1 = cap, w2 = cap;
    for(int i = 0; i < num; i++){
        x += (price[i]*a[i]);
        w1 -= (wei[i]*a[i]);

        y += (price[i]*b[i]);
        w2 -= (price[i]*b[i]);
    }
    if(w1 < 0)
        x = 0;
    if(w2 < 0)
        y = 0;
    return (x-y);
}

void neighborhood(int result[], int sol[]){
    int set, rep;
    if(dir == "ds1"){
        set = 10;
        rep = 17;
    }
    else if(dir == "ds2"){
        set = 17;
        rep = 20;
    }
    else if(dir == "ds3"){
        set = 10;
        rep = 10;
    }
    else{
        set = 10;
        rep = 12;
    }

    int trans[1010];
    for(int i = 0; i < set; i++){
        takeit(trans, sol);
        for(int j = 0; j < rep; j++){
            int select = randomnumber(0.0, double(num));
            if(trans[select] == 1)
                trans[select] = 0;
            else
                trans[select] = 1;
        }
        if(cal(trans, result) > 0)
            takeit(result, trans);
    }
}

void SA(int sol[]){
    int result[1010];
    for(int i = 0; i < num; i++){
        double print = randomnumber(0.0, 1.0);
        if(print < 0.5)
            sol[i] = 0;
        else
            sol[i] = 1;
    }
    double K = 2000, beta = 0.1;
    while(K > 1){
        neighborhood(result, sol);
        int d = cal(result, sol);
        if(d > 0){
            takeit(sol, result);
        }
        else{
            double pr = randomnumber(0.0, 1.0);
            if(pr > exp((double)d / K))
                takeit(sol, result);
        }
        K -= beta;
    }
}

int main(){
    cout << "Chose dataset ds1, ds2, ds3, or ds4 : ";
    cin >> dir;
    chdir(dir.c_str());

    fstream file;
    file.open("c.txt");
    file >> cap;
    file.close();

    file.open("w.txt");
    num = 0;
    while(file >> wei[num])
        num++;
    file.close();

    file.open("p.txt");
    num = 0;
    while(file >> price[num])
        num++;
    file.close();

    int sol[1010];
    SA(sol);
    
    dir = "ans_" + dir + ".txt";
    ofstream myfile;
    myfile.open(dir.c_str());
    int value = 0;
    for(int i = 0; i < num; i++){
    	if(sol[i])
    		value += price[i];
	}
	myfile << value << endl;
	for(int i = 0; i < num; i++)
		myfile << sol[i] << endl;
	myfile.close();

    cout << "Program finished!\n";
    return 0;
}
