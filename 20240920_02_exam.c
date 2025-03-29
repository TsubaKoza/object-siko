#include <stdio.h>
#include <time.h>  

long fibo( long );

int main( void ) {
   long num;
   clock_t start, end;  // 時間計測用変数
   double cpu_time_used;  // 実行時間を格納する変数

   printf("Please input number:");  
   scanf("%ld", &num );

   // 時間計測開始
   start = clock();

   // フィボナッチ計算
   long result = fibo( num );

   // 時間計測終了
   end = clock();

   // 実行時間を計算（秒単位）
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

   // 結果を表示
   printf("fibo(%ld)=%ld \n", num, result );
   printf("Execution time: %f seconds\n", cpu_time_used);

   return 0;
}

long fibo( long n ) {
   long fibo1 = 1;
   long fibo2 = 1;
   long fibo3 = 0;

   if(n == 1){
      return fibo1;
   }
   else if(n == 2){
      return fibo2;
   }
   else{
      for(int i = 2; i < n; i++) {
         fibo3 = fibo1 + fibo2;
         fibo1 = fibo2;
         fibo2 = fibo3;
      }
      return fibo3;
   }
}
