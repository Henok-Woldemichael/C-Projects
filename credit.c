#include <stdio.h>
#include <cs50.h>
#include <strings.h>
void get_input(long long int*val);
int num_digits(long long int value);
int split_num(int n, long long int value);
void card_type(int len, int first,int second,bool*lol);
bool validate(int len,long long int value);
//int start_num // Validate_ num / Card_type(int value) //why not just validate here is it a void???
long long int check_num = 0;
int length;
bool ha = false;



int main ()
{

    int first_num = 0;
    int second_num = 0;
    
    get_input(&check_num);
    length = num_digits(check_num);
   
    
    
    bool check_valid = validate(length,check_num);
  
    if(check_valid == true)
    {
    card_type(length,first_num,0,&ha);
    }
    
    
    
    if(ha == false)
    {
         printf("INVALID\n");
    }
    
    
}




void get_input(long long int *val)
{
    check_num = get_long("Enter the number: ");
   
}

int num_digits(long long int value)
{
    int count = 0;
    while(value != 0)
    {
        value/=10;
        count+=1;
    }

    return count;
}

int split_num(int n,long long int value)
{
    while(n--)
    {
        value/=10;
    }

    return value;
}

void card_type(int len,int first,int second, bool *lol)
{
   
    first = split_num(len - 1,check_num);
    second = split_num(len - 2, check_num) - (first * 10);
         
    
    if((first == 4) && (len == 13 || len == 14 || len == 15 || len == 16))
    {
       string bank = "VISA";
       printf("%s\n",bank);
       ha = true;
    }

    if((len == 16) && ((first == 5 && second == 1) || (first == 5 && second == 2) || (first == 5 && second == 3) || (first == 5 && second == 4) || (first == 5 && second == 5)) )
    {
        string bank = "MASTERCARD"; printf("%s\n",bank);
        ha = true;

    }
    
    if(((first == 3 && second == 4) || (first == 3 && second == 7)) && (len == 15))
    {
        string bank = "AMEX"; printf("%s\n",bank);
        ha = true;

    }
    
    
    
     
    
        
    
}

bool validate(int len,long long int value)
{
    
    int even = 0;
    int odd = 0;
    int position = 0;
    int digit;
    int sum;
    
    for(int i = 0; i<=length; i++)
    {
        digit = value%10;
        value/=10;
        
        if(i % 2 == 0)
        {
            
            even+=digit;
           
        }
        else
        { 
            
          if(2*digit>=10)
          {
              int pass = 2*digit;
        
              while(pass!=0)
              {
                 odd += pass % 10;
                  pass/=10;
              }
              
              
          }
          else
          {
              odd+= 2 * digit;
              
          }
          
           
        }
        
    }
   
    sum = even + odd;
    int valid_digit = sum%10;
    
   
   
    if ((valid_digit == 0) && (length > 12 && length != 14))
    {
       return true;
    }
  return false;
    
}
