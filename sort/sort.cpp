nclude<stdio.h>
#include<stdlib.h>
//
// help func
//
voidxx_print(intdata[],intn,intindex)
{
    /////
    inti=0;
    printf("index=%d : ",index);
    /////
    for(i=0;i<n;i++){
        printf("%d ",data[i]);
    }
    
    /////
    printf("\n");
}

//
// two swap value func
//
inlinevoidxx_swap(int*a,int*b)
{
    /////
    if(*a!=*b){
        *a^=*b;
        *b^=*a;
        *a^=*b;
    }
}

/////
inlinevoidxx_swap2(int*a,int*b)
{
    intc=*a;
    *a=*b;
    *b=c;
}

//
// ** 插入排序
//
// 将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。
// 即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。
// 要点：设立哨兵，作为临时存储和判断数组边界之用。
// 如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。
// 所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，所以插入排序是稳定的。
//
// 数字的描述：
// 设数组为a[0…n-1]。
// 1.初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1
// 2.将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。
// 3.i++并重复第二步直到i==n-1。排序完成。
//
// 时间复杂度：O（n^2）.
//
void alg_insert_sort(int data[], int n)
{
    int i = 0;
    int j = 0;
    
    // 遍历所有元素
    for(i=1; i<n; i++){
        // 如果前一个数大于后一个数 则不用
        if(data[i] < data[i+1]){
            // 设置哨兵元素
            int xx=data[i];
            // 找到比XX小的元素，XX前面的元素都后移，　然后插入

            for(j=i-1; j>=0 && data[j]>xx; j--){
                data[j+1] = data[j];// 后移
            }
            data[j+1] = xx;// 插入
        }

        /////
        xx_print(data, n, i);
    }
}

//
// * 选择 排序—简单选择排序（Simple Selection Sort）
//
// 在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换.
// 依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止。
//
// 时间复杂度：O（n^2）.
//
void alg_select_sort(int data[],int n)
{
inti=0;
intj=0;
// 最小下标
intmaxId=0;
/////
for(i=0;i<n;i++){
maxId=i;
// 找到最小元素的下标
for(j=i+1;j<n;j++){
/////
if(data[maxId]<data[j]){
maxId=j;
}
}
// 交换两个数
xx_swap(&data[i],&data[minId]);
/////
xx_print(data,n,i);
}
}
//
// *简单选择排序的改进—— 二元选择排序
//
// 简单选择排序，每趟循环只能确定一个元素排序后的定位。
// 我们可以考虑改进为每趟循环确定两个元素（当前趟最大和最小记录）的位置,从而减少排序所需的循环次数。
// 改进后对n个数据进行排序，最多只需进行[n/2]趟循环即可。
//
voidalg_select_sort2(intdata[],intn)
{
inti,j,minId,maxId;
/////
for(i=1;i<n/2;i++){
minId=maxId=i;
// 查找最大最小两个下标
for(j=i+1;j<n-1;j++){
// 确定最大数的下标
if(data[j]>data[maxId]){
maxId=j;
continue;
}
// 确定最小数的下标
if(data[j]<data[minId]){
minId=j;
}
}
// 交换两个数
xx_swap(&data[i-1],&data[minId]);
xx_swap(&data[n-1],&data[maxId]);
/////
xx_print(data,n,i);
}
}
//
// 插入排序—希尔排序（Shell`s Sort）
//
// 希尔排序又叫缩小增量排序. 先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，
// 然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。
// 因为直接插入排序在元素基本有序的情况下（接近最好情况），效率是很高的。
//
// 希尔排序时效分析很难，关键码的比较次数与记录移动次数依赖于增量因子序列d的选取.
//
// ----------------------------------------------
// @param int dk 缩小增量，如果是直接插入排序，dk=1
//
voidalg_shell_insert_sort(intdata[],intn,intdk)
{
inti=0;
intj=0;
// 遍历所有元素
for(i=dk;i<n;i++){
/////
if(data[i]<data[i+dk]){
// 设置哨兵元素
intxx=data[i];
// 找到比XX小的元素，XX前面的元素都后移，　然后插入。
for(j=i-dk;j>=0&&data[j]>xx;j-=dk){
data[j+dk]=data[j];
}
/////
data[j+dk]=xx;
}
/////
xx_print(data,n,i);
}
}
//
voidalg_shell_sort(intdata[],intn)
{
intdk=n/2;
/////
while(dk>=1){
/////
alg_shell_insert_sort(data,n,dk);
dk=dk/2;
}
}
//
// 希尔排序
//
voidalg_shell_sort2(intdata[],intn)
{
inti,j,gap;
for(gap=n/2;gap>0;gap/=2){
for(i=gap;i<n;i++){
for(j=i-gap;j>=0&&data[j]>data[j+gap];j-=gap){
xx_swap(data[j],data[j+gap]);
}
}
}
}
//
// 交换排序—冒泡排序（Bubble Sort）
//
// 在要排序的一组数中，对当前还未排好序的范围内的全部数，
// 自上而下对相邻的两个数依次进行比较和调整，让较大的数往下沉，较小的往上冒。
// 即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换。
// 冒泡排序毕竟是一种效率低下的排序方法，在数据规模很小时，可以采用。
// 数据规模比较大时，最好用其它排序方法。
//
// -------------------------------------
// 依据说明写的 冒泡排序 bubble_sort0
//
voidalg_bubble_sort0(intdata[],intn)
{
inti,j;
/////
for(i=0;i<n-1;i++){
// n-i i是已冒过了的
for(j=0;j<n-i-1;j++){
// 符合条件就交换
if(data[j]>data[j+1]){
xx_swap(&data[j],&data[j+1]);
}
}
}
}
//
// 优化后冒泡排序bubble_sort1，设置一个标志flag，如果这一趟发生了交换，则为1，否则为0。
// 明显如果有一趟没有发生交换，说明排序已经完成。
//
voidalg_bubble_sort1(intdata[],intn)
{
inti=0;
intk=n;
// 是否已经发生交换
intflag=1;
/////
while(flag){
flag=0;
// i=1 所以下面 data[i-1] 中是i-1
for(i=1;i<k;i++){
// 如果 i-1的值大于i的值，就交换
if(data[i-1]>data[i]){
xx_swap(&data[i-1],&data[i]);
/////
flag=1;
}
}
/////
k--;
}
}
//
// 改进后的冒泡排序 bubble_sort
// 每趟排序中进行正向和反向两遍冒泡的方法一次可以得到两个最终值(最大者和最小者) ,
// 从而使排序趟数几乎减少了一半。
//
voidalg_bubble_sort(intdata[],intn)
{
intlow=0;
inthigh=n-1;
inti=0;
/////
while(low<high){
// 正向冒泡,找到最大者
for(i=low;i<high;i++){
/////
if(data[i]>data[i+1]){
xx_swap(&data[i],&data[i+1]);
}
}
// 修改high值, 前移一位
high--;
// 反向冒泡,找到最小者
for(i=high;i>low;i--){
/////
if(data[i]<data[i-1]){
xx_swap(&data[i],&data[i-1]);
}
}
// 修改low值,后移一位
low++;
}
}
//
// 交换排序—快速排序（Quick Sort）
// 速排序称为分治法
// 基本思想：
// 1)选择一个基准元素,通常选择第一个元素或者最后一个元素,
// 2)通过一趟排序讲待排序的记录分割成独立的两部分，其中一部分记录的元素值均比基准元素值小。
// 另一部分记录的 元素值比基准值大。
// 3)此时基准元素在其排好序后的正确位置
// 4)然后分别对这两部分记录用同样的方法继续进行排序，直到整个序列有序。
//
// -------------------------------------------------------
// 快速排序由于排序效率在同为O(N*logN)的几种排序方法中效率较高
//
int_quick_sort_first(int data[],int low,int high)
{
    // 基准元素
    int privotKey = data[low];
    // 从表的两端交替地向中间扫描
    while(low < high){
        
        // 从high 所指位置向前搜索，至多到low+1 位置。
        // 将比基准元素小的 > 交换到低端
        while(low < high && data[high] >= privotKey) --high;
        xx_swap(&data[low],&data[high]);
        
        /////
        while(low < high&&data[low] <= privotKey) ++low;
        xx_swap(&data[low], &data[high]);
    }
    //xx_print(a,high low);
    return low;
}

void alg_quick_sort(int data[],int low,int high)
{
    if(low<high){

        // 将表一分为二
        int pos=_quick_sort_first(data,low,high);
    
        // 递归对低子表递归排序
        alg_quick_sort(data,low,pos-1);
        
        // 递归对高子表递归排序
        alg_quick_sort(data,pos+1,high);
    }
}

//
//
//

void  _quick_sort_ext(int data[],int low,int high,int k)
{
    int pos = 0;
    // 长度大于k时递归, k为指定的数
    if(high-low > k){
        // 调用的Partition算法保持不变
        pos=_quick_sort_first(data,low,high);
        _quick_sort_ext(data,low,pos-1,k);
        _quick_sort_ext(data,pos+1,high,k);
    }
}

//
// 快速排序是通常被认为在同数量级（O(nlog2n)）的排序方法中平均性能最好的。
// 但若初始序列按关键码有序或基本有序时，快排序反而蜕化为冒泡排序。
// 为改进之，通常以“三者取中法”来选取基准记录，即将排序区间的两个端点与中点三个记录关键码居中的调整为支点记录。
// 快速排序是一个不稳定的排序方法。
//
// 在改进算法中,只对长度大于k的子序列递归调用快速排序,让原序列基本有序，然后再对整个基本有序序列用插入排序算法排序。
// 实践证明，改进后的算法时间复杂度有所降低，且当k取值为 8 左右时,改进算法的性能最佳。
//
//-----------------------------------------------------------------
// * @param int k k为快速排序算法的长度。 为0时，则为普通的快速排序。
// * 先以k为长度进行快速排序， 然后再进行插入排序。
//
void alg_quick_sort_ext(int data[],int n,int k)
{
    // 先调用改进快速排序算法使之基本有序
    _quick_sort_ext(data,0,n,k);
    // 再用插入排序对基本有序序列排序
    alg_insert_sort(data,n);
}

//
// 归并排序（Merge Sort）
//
// 基本思路:
// 将数组分成二组A，B，如果这二组组内的数据都是有序的，那么就可以很方便的将这二组数据进行排序。
// 如何让这二组组内数据有序了？
// 可以将A，B组各自再分成二组。依次类推，当分出来的小组只有一个数据时，
// 可以认为这个小组组内已经达到了有序，然后再合并相邻的二个小组就可以了。
// 这样通过先递归的分解数列，再合并数列就完成了归并排序。
//
// 归并排序的效率是比较高的，设数列长为N，将数列分开成小数列一共要logN步，
// 每步都是一个合并有序数列的过程，时间复杂度可以记为O(N)，故一共为O(N*logN)。
//
// 对空间要求比较高， 要申请对等的空间
//
// 将有序数组src1[]和src2[]合并到dest[]中
voidalg_merge_array(intsrc1[],intlen1,intsrc2[],intlen2,intdest[])
{
inti,j,k;
i=j=k=0;
/////
while(i<len1&&j<len2){
/////
if(src1[i]<src2[j])
dest[k++]=src1[i++];
else
dest[k++]=src2[j++];
}
/////
while(i<len1)dest[k++]=src1[i++];
while(j<len2)dest[k++]=src2[j++];
}
//
// -------------------------------------------
//
// 把[first, mid] 和[mid+1, last] 合并到data中
//
void_merg_array(intdata[],intfirst,intmid,intlast,inttemp[])
{
inti=first,m=mid;
intj=mid+1,n=last;
intk=0;
/////
while(i<=m&&j<=n){
/////
if(data[i]<=data[j]){
temp[k++]=data[i++];
}
else{
temp[k++]=data[j++];
}
}
/////
while(i<=m)temp[k++]=data[i++];
while(j<=n)temp[k++]=data[j++];
/////
for(i=0;i<k;i++){
data[first+i]=temp[i];
}
}
void_merg_sort(intdata[],intfirst,intlast,inttemp[])
{
if(first<last){
intmid=(first+last)/2;
/////
_merg_sort(data,first,mid,temp);
_merg_sort(data,mid+1,last,temp);
////
_merg_array(data,first,mid,last,temp);
}
}
//
// 合并排序，对空间要求比较高， 要申请对等的空间
//
intalg_merge_sort(intdata[],intn)
{
int*p=(int*)malloc(n*sizeof(int));
if(p==NULL)return-1;
/////
_merg_sort(data,0,n-1,p);
/////
free(p);
/////
return0;
}
//
// 选择排序—堆排序（Heap Sort）
//
// 堆排序是一种树形选择排序，是对直接选择排序的有效改进。
//
voidalg_head_sort(intdata[],intn)
{
}
//
// 桶排序/基数排序(Radix Sort)
//
voidalg_radix_sort()
{
}
//
#defineUNIT_MAX8
//
inttest_data[UNIT_MAX]={3,1,5,7,2,4,9,6};

//

int main()
{
    //alg_insert_sort(test_data, UNIT_MAX);
    //alg_shell_sort(test_data, UNIT_MAX);
    //alg_select_sort(test_data, UNIT_MAX);
    //salg_elect_sort2(test_data, UNIT_MAX);
    //alg_bubble_sort(test_data, UNIT_MAX);
    alg_merge_sort(test_data,UNIT_MAX);
    xx_print(test_data,UNIT_MAX,UNIT_MAX);
    /////
    return 0;
}

