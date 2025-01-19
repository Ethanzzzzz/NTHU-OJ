#include <stdio.h>
#include <string.h>

int main()
{
    char a[500], b[500];
    scanf("%s",a);//輸入
    scanf("%s",b);
    int da = 0, db = 0;//用於錄每個數字的長度
    //將ascii碼轉換成數字
    int tmpa[500] = {0};
    for(int i = 0; a[i] != 0; i++)
    {
        if(a[i] == ','){
            tmpa[i+1] = ',';
            da++;
            continue;             //這邊是往後移 從1開始
        }
        tmpa[i+1] = a[i] - '0';
        da++;
    }
    for(int i = 1; i <= da; i++)
    {
        a[i] = tmpa[i];
    }
    int tmpb[500] = {0};
    for(int i = 0; b[i] != 0; i++)
    {
        if(b[i] == ','){
            tmpa[i+1] = ',';
            db++;
            continue;
        }
        tmpb[i+1] = b[i] - '0';
        db++;
    }
    for(int i = 1; i <= db; i++)
    {
        b[i] = tmpb[i];
    }
    //右對齊處理
    int d;//有效運算長度
    if(da > db)
    {
        d = da;
        int tmp[500];
        for(int i = d; i > 1; i--)
        {
            tmp[i] = b[i - (da - db)];
        }
        for(int i = 1; i <= d; i++)
        {
            b[i] = tmp[i];
        }
        for(int i=1;i<=da-db;i++){
            b[i] = 0;
        }
    }
    if(db > da)
    {
        d = db;
        int tmp[500];
        for(int i = d; i > 1; i--)
        {
            tmp[i] = a[i - (db - da)];
        }
        for(int i = 1; i <= d; i++)
        {
            a[i] = tmp[i];
        }
        for(int i=1;i<=db-da;i++){
            a[i] = 0;
        }
    }
    if(da == db) d = da;
    //模擬手算加法
    char c[510] = {0}, add = 0;
    for(int i = d; i > 0; i--)
    {
        if(a[i] == ','){
            c[i] = ',';
            continue;
        }
        if(b[i] == ','){
            c[i] = ',';
            continue;
        }
        else{    
            c[i] = a[i] + b[i] + add;
            add = c[i]/10;
            c[i] %= 10;
        }
    }
    
    
    
    //輸出
    if(add != 0) printf("%d",add);
    c[0] = ',';
    int start;
    if(add == 0){
        start = 1;
    }
    else if(d%4 == 2){
        start = 1;
    }
    else{
        start = 0;
    }
    
    for(int i=start; i<=d; i++)
    {
        if(c[i] == ','){
            printf(",");
            continue;
        }
        printf("%d",c[i]);
    }
    printf("\n");
}