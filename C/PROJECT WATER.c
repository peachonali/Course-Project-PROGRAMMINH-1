#include <stdio.h>
#include <unistd.h> // สำหรับการใช้ sleep

#define LOW_MONEY 2 // ค่าคงที่เช็คเงินน้อย

int TopUP()  //ฟังก์ชันเติมเหรียญ
{   
    int money ;
    scanf("%d", &money);
    
    if(money <= 0) // เงื่อนไขตรวจสอบจำนวนเต็มบวก
    {
        printf("\n\033[1;31mข้อมูลไม่ถูกต้อง: กรุณาป้อนจำนวนเงินที่เป็นจำนวนเต็มบวก\n\033[0m");
        return 0;
    }
    
    printf("\033[1;32m\t\t\t\t\t\t\tเงินสดเข้าตู้ %d baht \n\033[0m", money);
    printf("...........................................................................\n");
    return money;
}


int bottles() //ฟังก์ชันกรอกขวดน้ำ
{   
    int liter ;
    scanf("%d", &liter);
    
    if(liter <= 0) // เงื่อนไขตรวจสอบจำนวนเต็มบวก
    {
        printf("\n\033[1;31mข้อมูลไม่ถูกต้อง: กรุณาป้อนจำนวนขวดที่เป็นจำนวนเต็มบวก\n\033[0m");
        return 0;
    }
    
    printf("\033[1;32m\t\t\t\t\t\t\tขวดน้ำเข้าตู้ %d bottle \n\033[0m", liter);
    printf("...........................................................................\n");
    return liter;
}


void dispenseWater(int *money,int *liter)  //ฟังก์ชันกดน้ำ
{  
    int totalCost = *liter ; //ลิตรละ 1 บาท
    *money -= totalCost ; //หักที่ละ 1 บาท เมื่อเติมน้ำ
   
    printf("\033[1;32m\t\t\t\t\t\t\tน้ำไหลออกมา %d ลิตร\n\033[0m", *liter);
    printf("\033[1;32m\t\t\t\t\t\t\tจำนวน %d ขวด \n\033[0m",totalCost);
    printf("\033[1;32m\t\t\t\t\t\t\tเงินทอนคงเหลือ %d baht \n\033[0m", *money);
    printf("...........................................................................\n");
    
    if (*money < LOW_MONEY)  // เงื่อนไข แจ้งเตือนเงินน้อย
    {
        printf("\n\033[1;31mแจ้งเตือน: ยอดเงินในตู้กดน้ำเหลือน้อย กรุณาเติมเงินถ้าต้องการเติมอีก\n\033[0m");
    }
}


void recordUsage(int money, int liter)  // ฟังก์ชันบันทึกประวัติการใช้งาน
{
    printf("\nบันทึกประวัติการใช้งาน: เงินที่ใส่เข้าตู้ %d baht, จำนวนขวดที่เติม%d bottle\n", money, liter);
}



void contactUser()  // ฟังก์ชันส่วนติดต่อผู้ใช้
{
    printf("\nติดต่อผู้ใช้ : กรุณาติดต่อผู้พัฒนาที่ Phisanu.phoy@bumail.net สำหรับคำถามหรือข้อเสนอแนะ\n");
    printf("ติดต่อผู้ใช้ : กรุณาติดต่อผู้พัฒนาที่ Sanphit.mowa@bumail.net สำหรับคำถามหรือข้อเสนอแนะ\n");
}


int main () 
{
    int option;
    int liter = 0 ;
    int money = 0 ;
    
    printf("\n\033[1;31mยินดีต้อนรับการใช้บริการน้ำดื่ม\n\033[0m");
    printf("\033[4mWater 1 baht / Water 1 liter \n\033[0m"); 
    printf("...........................................................................\n");
    
    do {
        
        printf("\033[3;374m\nเลือกรายการที่ต้องการ\n\033[0m");
        printf("\033[1;36m 1. เติมเงิน\n\033[0m");
        printf("\033[1;36m 2. กรอกขวดน้ำ\n\033[0m");
        printf("\033[1;36m 3. กดน้ำ\n\033[0m");
        printf("\033[1;36m 4. ติดต่อผู้พัฒนา\n\033[0m");
        printf("\033[1;36m 5. ออกจากโปรแกรม\n\033[0m");
        scanf("%d", &option);

        switch (option) 
        {
            
            case 1:
                printf("\n\033[1;32mป้อนจำนวนเงินที่ต้องการใส่เข้าตู้ (บาท): \033[0m");
                money += TopUP();
                break;
                
                
            case 2:
                printf("\n\033[1;32mป้อนจำนวนขวดน้ำที่ต้องการเติม: \033[0m");
                liter += bottles();
                break;
            
            
            case 3:
            if (liter > 0 && money >= liter ) //เงื่อนไขตรวจสอบการลืมใส่เงินและขวด
            {
                
                printf("\n\033[1;32mกดเพื่อเติมน้ำ: \n\033[0m");
                
                for (int i = 0; i < liter; i++) 
                {
                    printf("\tกำลังเติมน้ำขวดที่ %d...\n", i + 1);
                    sleep(1); // slow
                }
                
                dispenseWater(&money,&liter);
                recordUsage(money, liter); // เรียกใช้ฟังก์ชันบันทึกประวัติการใช้งาน
            }
            else
            {
                printf("\n\033[1;31mกรุณาเติมเงินหรือกรอกขวดน้ำก่อน \n\033[0m");
            }
                break;
              
             
            case 4:
                contactUser(); // เรียกใช้ฟังก์ชันส่วนติดต่อผู้ใช้
                break;
              
              
            case 5:
                printf("\n\033[1;31mออกจากโปรแกรม\033[0m");
                return 0;
                
                
            default:
                printf("\n\033[1;31mกรุณาเลือกรายการที่ถูกต้อง\n\033[0m");
        }
    } while(option != 5);
    
    return 0;
}









