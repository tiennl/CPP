int pagesNumbering(int n)
{
    int number_of_digits = 0; 
    for (int i = 1; i <= n; i *= 10) 
        number_of_digits += (n - i + 1); 
    return number_of_digits;
}
// Dem so luong chu so can dung de in mot cuon sach co n trang
// https://www.geeksforgeeks.org/count-total-number-digits-1-n/
