/******************************************************************************
 *
 * Freescale Semiconductor Inc.
 * (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
 * ALL RIGHTS RESERVED.
 *
 ******************************************************************************
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
 * IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 **************************************************************************//*!
 *
 * @file main.c
 *
 * @author
 *
 * @version
 *
 * @date
 *
 * @brief   This software is the USB driver stack for S08 family
 *****************************************************************************/
  #include "types.h"
  #include "derivative.h" /* include peripheral declarations */
  #include "user_config.h"
  #include "RealTimerCounter.h"
  #include "Wdt_kinetis.h"
  #include "TWR_K50_UI.h"
  #include "stdio.h"
  #include "uart.h"
  #include "gsm.h"
  #include "lptmr.h"
  #include "string.h"
  #include <MK53N512CMD100.h>
  #include "Main_App.h"
  #include <stdlib.h>

extern uint_32 ___VECTOR_RAM[];            //Get vector table that was copied to RAM

__ramfunc void set_sys_dividers(unsigned int outdiv1, unsigned int outdiv2, unsigned int outdiv3, unsigned int outdiv4);

void ISR_Tracker (void);  //Erase

/*****************************************************************************
 * Global Functions Prototypes
 *****************************************************************************/
#if MAX_TIMER_OBJECTS
extern uint_8 TimerQInitialize(uint_8 ControllerId);
#endif
extern void TestApp_Init(void);
extern void TestApp_Task(void);
extern void string_tx_gsm(char *str);
extern void string_tx1_gsm(char *str);
extern void string_rx_gsm(void);
void UART3_IRQHandler(void);
void IRQ_enable(uint32_t irq);
void check_string( char *string1,char *string2);
#define BSP_CLOCK_SRC                   (8000000ul)       // crystal, oscillator freq
#define BSP_REF_CLOCK_SRC               (2000000ul)       // must be 2-4MHz

#define BSP_CORE_DIV                    (1)
#define BSP_BUS_DIV                     (1)
#define BSP_FLEXBUS_DIV                 (1)
#define BSP_FLASH_DIV                   (2)

// BSP_CLOCK_MUL from interval 24 - 55
#define BSP_CLOCK_MUL                   (24)    // 48MHz

#define BSP_REF_CLOCK_DIV               (BSP_CLOCK_SRC / BSP_REF_CLOCK_SRC)

#define BSP_CLOCK                       (BSP_REF_CLOCK_SRC * BSP_CLOCK_MUL)
#define BSP_CORE_CLOCK                  (BSP_CLOCK / BSP_CORE_DIV)          // CORE CLK, max 100MHz
#define BSP_SYSTEM_CLOCK                (BSP_CORE_CLOCK)                    // SYSTEM CLK, max 100MHz
#define BSP_BUS_CLOCK                   (BSP_CLOCK / BSP_BUS_DIV)       // max 50MHz
#define BSP_FLEXBUS_CLOCK               (BSP_CLOCK / BSP_FLEXBUS_DIV)
#define BSP_FLASH_CLOCK                 (BSP_CLOCK / BSP_FLASH_DIV)     // max 25MHz

/*****************************************************************************
 * Local Functions Prototypes
 *****************************************************************************/
static void Init_Sys(void);
static unsigned char pll_init();
//static void wdog_disable(void); /*@test*/
static void StartKeyPressSimulationTimer(void);
static void KeyPressSimulationTimerCallback(void);

void time_delay_ms(unsigned int count_val);

/****************************************************************************
 * Global Variables
 ****************************************************************************/
uint_8 kbi_stat_sim;
volatile uint_8 kbi_stat;	   /* Status of the Key Pressed */
unsigned int Fault;
char read_str[50];
char read_data[100];
char *str_array;
char check[10]="CHECK";
char SMS_String[]="Test";
char a[]="Test Program";
char *p;
char ch='\0';
char line[100];

/*****************************************************************************
 * Global Functions
 *****************************************************************************/
/******************************************************************************
 * @name        main
 *
 * @brief       This routine is the starting point of the application
 *
 * @param       None
 *
 * @return      None
 *
 *****************************************************************************
 * This function initializes the system, enables the interrupts and calls the
 * application
 *****************************************************************************/
int rxflag=0;
char rxBuffer[200];
int rxBuffer_intex=0;
int rxend=0;
void  main(void)
{   
    Init_Sys();        /* initial the system */
    
         SIM_SCGC4 |=  SIM_SCGC4_UART2_MASK ;   // SIM_SCGC4_UART3_MASK ; /* old declaration */
                       
         SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK
                      | SIM_SCGC5_PORTB_MASK
                      | SIM_SCGC5_PORTC_MASK
                      | SIM_SCGC5_PORTD_MASK
                      | SIM_SCGC5_PORTE_MASK );
    
    int core_clk_khz= 50*1000;
     
    long int periph_clk_khz = core_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV2_MASK) >> 24)+ 1);
         
        
                 /* Enable the UART2_TXD function on PTD3 */
  		PORTD_PCR3 = PORT_PCR_MUX(0x3); // UART is alt3 function for this pin

  		/* Enable the UART2_RXD function on PTD2 */
  		PORTD_PCR2 = PORT_PCR_MUX(0x3); // UART is alt3 function for this pin 
         
    
       uart_init (UART2_BASE_PTR, periph_clk_khz, 9600); 
 
    while(1)
    {
      
       uart_putchar(UART2_BASE_PTR ,'a');
       
        //uart_putchar(UART2_BASE_PTR ,'\n');
       
    }  
       
                
    
    
     /**************************** Old Code ******************************/ 
    
          /*  SIM_SCGC4 |=  SIM_SCGC4_UART3_MASK ;
            SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK
                      | SIM_SCGC5_PORTB_MASK
                       | SIM_SCGC5_PORTC_MASK
                      | SIM_SCGC5_PORTD_MASK
                      | SIM_SCGC5_PORTE_MASK );*/
	    
     
            /* Enable the UART0_TXD function on PTD6 */
         //  PORTD_PCR6 = PORT_PCR_MUX(0x3); // UART is alt3 function for this pin

            /* Enable the UART0_RXD function on PTD7 */
      //    PORTD_PCR7 = PORT_PCR_MUX(0x3); // UART is alt3 function for this pin
    
	           /*Enable the UART3_TXD function on PTC17 */
  	//	PORTC_PCR17 = PORT_PCR_MUX(0x3); // UART is alt3 function for this pin

  		/* Enable the UART3_RXD function on PTC16 */
  	//	PORTC_PCR16 = PORT_PCR_MUX(0x3); // UART is alt3 function for this pin
                
                 /*Enable the UART3_RXD function on PTB10*/     
	//    PORTB_PCR10 = PORT_PCR_MUX(0x3);
            
            /*Enable the UART3_TXD function on PTB11*/
        //     PORTB_PCR11=  PORT_PCR_MUX(0x3);
            
   /**************************** Old Code ******************************/             
   /**************************** Old Code ******************************/  	    
/* #if MAX_TIMER_OBJECTS
    (void)TimerQInitialize(0);
#endif  */
   /**************************** Old Code ******************************/     
// (void)TestApp_Init(); /* Initialize the USB Test Application */
//     StartKeyPressSimulationTimer();
    
    /**************************** Old Code *****************************
 /*  int core_clk_khz= 50*1000;
     
 long int periph_clk_khz = core_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV2_MASK) >> 24)+ 1); */
   
    /**************************** Old Code *****************************/
 
/**************************** Old Code *****************************/    
    
 /*uart_init (UART3_BASE_PTR,periph_clk_khz, 115200);
 uart_init (UART0_BASE_PTR, core_clk_khz, 9600);*/
    
/**************************** Old Code *****************************/ 
    
  /**************************** Old Code *****************************/  
    
  //IRQ_enable(51);
 // string_tx1_gsm("Hello");
  
  
  
   //   string_tx_gsm("AT\r");
 //time_delay_ms(1000);
    //if(rxflag){
     // string_tx1_gsm(rxBuffer);
     // rxflag=0;
     // rxBuffer_intex=0;
   //}
 //string_tx_gsm("AT+CMGF=1\r");
  //time_delay_ms(1000);
    // if(rxflag){
     // string_tx1_gsm(rxBuffer);
     // rxflag=0;
    //  rxBuffer_intex=0;
  // }
 //string_tx_gsm("AT+CMGR=26\r");
 //time_delay_ms(1000);

   //if(rxflag){
      //string_tx1_gsm(rxBuffer);
      //rxflag=0;
     // rxBuffer_intex=0;
   //}
  //if(strstr(rxBuffer,"CHECKOK" ) != NULL) {
   //string_tx1_gsm("self check ok");
   //} 
 // else {
   // string_tx1_gsm("self check failed");
 //   }
   
   
   

 
  //  while(1);
    
/**************************** Old Code *****************************/    

}

void UART3_IRQHandler(void)
{
    
    if ((UART_S1_REG(UART3_BASE_PTR) & UART_S1_RDRF_MASK)){
    rxBuffer[rxBuffer_intex]=UART_D_REG(UART3_BASE_PTR); 
    if(rxBuffer[rxBuffer_intex]=='\n'||rxBuffer[rxBuffer_intex]=='\r'||rxBuffer[rxBuffer_intex]=='\0'){
      rxflag=1;
      rxBuffer[rxBuffer_intex]='\0';
    }
    else
    rxBuffer_intex++;
    }

}

/*void UART3_IRQHandler(void)
{
  int i;
  for(i=0;i<50;i++)
  {
  str_array = (char*)malloc(strlen(read_data)*sizeof(char*));
   read_data[i]=UART_D_REG(UART3_BASE_PTR);
   strcpy(str_array,read_data);
   if(read_data[i]=='\r')
   {
     read_str[i]='\0';
     break;
   }
}
string_tx1_gsm(read_data);
 UART3_S1 &=~(1<<UART_S1_RDRF_SHIFT);
}
*/

/*void UART3_IRQHandler(void)
  
{
int i=0,j=1;
read_str = (char*)malloc(sizeof(char)*4);
while(ch!='\n')
{
    ch = UART_D_REG(UART3_BASE_PTR);     //read the input from keyboard standard input
    //re-allocate (resize) memory for character read to be stored
    read_str = (char*)realloc(read_str,j*sizeof(char)*4);
    read_str[i] = ch;  //store read character by making pointer point to c
    i++;
    j++;
}
read_str[i]='\0';   //at the end append null character to mark end of string

free(read_str);   //important step the pointer declared must be made free 
 string_tx1_gsm(read_str);
    UART3_S1 &=~(1<<UART_S1_RDRF_SHIFT);
 }
*/
void IRQ_enable(uint32_t irq)

{

uint32_t div;

 

// Enable IRQ in NVIC

div = irq / 32u;

 

switch(div)

{

  case 0u:

      NVICICPR1 |= 1 << (irq % 32u);

      NVICISER0 |= 1 << (irq % 32u);

      break;

 

  case 1u:

      NVICICPR1 |= 1 << (irq % 32u);

      NVICISER1 |= 1 << (irq % 32u);

      break;

 

  case 2u:

      NVICICPR2 |= 1 << (irq % 32u);

      NVICISER2 |= 1 << (irq % 32u);

      break;

}

}
/*void check_string( char *string1,char *string2)
{
  
  if(strstr(string1,string2))
    {
      uart_putchar(UART0_BASE_PTR ,'Y');
    } 
else
{
  uart_putchar(UART0_BASE_PTR ,'N');
}
}
*/

       //string_tx_gsm(first);
       // time_delay_ms(1000);
       
       //uart_putchar(UART3_BASE_PTR ,UART_D_REG(UART3_BASE_PTR));
       
      //string_rx_gsm();
       //time_delay_ms(500);
  
     //string_tx_gsm(test_gsm);
    // time_delay_ms(500);
      //string_rx_gsm();
 
   
   //c=uart_getchar(UART3_BASE_PTR);
   //uart_putchar(UART0_BASE_PTR ,c);
      


    
         
        
       




/*****************************************************************************
 * Local Functions
 *****************************************************************************/

/******************************************************************************
 * @name        StartKeyPressSimulationTimer
 *
 * @brief       This routine is used to start the timer for generating key press events
 *              Used on boards without buttons
 *
 * @param       None
 *
 * @return      None
 *
 *****************************************************************************
 *
 *****************************************************************************/
static void StartKeyPressSimulationTimer(void)
{
  TIMER_OBJECT TimerObject;
			
  TimerObject.msCount = KEY_PRESS_SIM_TMR_INTERVAL;
  TimerObject.pfnTimerCallback = KeyPressSimulationTimerCallback;
  (void)AddTimerQ(&TimerObject);
}

/******************************************************************************
 * @name        KeyPressSimulationTimerCallback
 *
 * @brief       This routine is used to generate simulated key press events
 *              It is called at KeyPressSimulationTimer expire time
 *              Used on boards without buttons
 *
 * @param       None
 *
 * @return      None
 *
 *****************************************************************************
 *
 *****************************************************************************/
static void KeyPressSimulationTimerCallback(void)
{
	 /* generate the button press */
	 kbi_stat_sim = (uint_8)((kbi_stat_sim << 1) & (uint_8)0x0F);
	 
	 if(kbi_stat_sim == 0)
	 {
	  kbi_stat_sim = 1;
	 }
	 
	 kbi_stat = kbi_stat_sim;
	 
	 /* re-trigger the timer */
	 StartKeyPressSimulationTimer();
}

/*****************************************************************************
 *
 *    @name     GPIO_Init
 *
 *    @brief    This function Initializes LED GPIO
 *
 *    @param    None
 *
 *    @return   None
 *
 ****************************************************************************
 * Intializes the GPIO
 ***************************************************************************/
void GPIO_Init()
{

}

/******************************************************************************
 * @name       all_led_off
 *
 * @brief      Switch OFF all LEDs on Board
 *
 * @param	   None
 *
 * @return     None
 *
 *****************************************************************************
 * This function switch OFF all LEDs on Board
 *****************************************************************************/
static void all_led_off(void)
{
	GPIOC_PSOR |= 1 << 8 | 1 << 9;
}

/******************************************************************************
 * @name       display_led
 *
 * @brief      Displays 8bit value on Board LEDs
 *
 * @param	   val
 *
 * @return     None
 *
 *****************************************************************************
 * This function displays 8 bit value on Board LED
 *****************************************************************************/
void display_led(uint_8 val)
{
    //uint_8 i = 0; /*@test*/
    all_led_off();

	val &= 0x03;
	if(val & 0x1)
		GPIOC_PCOR |= 1 << 8;
	if(val & 0x2)
		GPIOC_PCOR |= 1 << 9;
}
/*****************************************************************************
 *
 *    @name     Init_Sys
 *
 *    @brief    This function Initializes the system
 *
 *    @param    None
 *
 *    @return   None
 *
 ****************************************************************************
 * Intializes the MCU, MCG, KBI, RTC modules
 ***************************************************************************/
static void Init_Sys(void)
{

	  //uint_32 i,n;/*@test*/
	  /* Point the VTOR to the new copy of the vector table */                  
        SCB_VTOR = (uint_32)___VECTOR_RAM;
		
	NVICICER2|=(1<<9);                     //Clear any pending interrupts on USB
	NVICISER2|=(1<<9);                     //Enable interrupts from USB module  

    /* SIM Configuration */
	pll_init();

    MPU_CESR=0x00;
    
    /************* USB Part **********************/
    /*********************************************/   
    // PLL/FLL selected as CLK source
    SIM_CLKDIV2 &= SIM_CLKDIV2_USBFRAC_MASK | SIM_CLKDIV2_USBDIV_MASK;
    SIM_CLKDIV2|= SIM_CLKDIV2_USBDIV(0);
    
    SIM_SCGC4|=(SIM_SCGC4_USBOTG_MASK);             // USB Clock Gating
    SIM_SOPT2  |= SIM_SOPT2_USBSRC_MASK | SIM_SOPT2_PLLFLLSEL_MASK;
    SIM_SOPT1 |= SIM_SOPT1_USBREGEN_MASK;

}

/*****************************************************************************
 * @name     wdog_disable
 *
 * @brief:   Disable watchdog.
 *
 * @param  : None
 *
 * @return : None
 *****************************************************************************
 * It will disable watchdog.
  ****************************************************************************/
//static void wdog_disable(void) /*@test*/
//{
//	/* Write 0xC520 to the unlock register */
//	WDOG_UNLOCK = 0xC520;
//	
//	/* Followed by 0xD928 to complete the unlock */
//	WDOG_UNLOCK = 0xD928;
//	
//	/* Clear the WDOGEN bit to disable the watchdog */
//	WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;
//}
/*****************************************************************************
 * @name     pll_init
 *
 * @brief:   Initialization of the MCU.
 *
 * @param  : None
 *
 * @return : None
 *****************************************************************************
 * It will configure the MCU to disable STOP and COP Modules.
 * It also set the MCG configuration and bus clock frequency.
 ****************************************************************************/
static unsigned char pll_init()
{      
  //This assumes that the MCG is in default FEI mode out of reset.
  
  //PLL configuration for Kinetis K53 using a 50MHz Clock
    
// Enable external oscillator, RANGE=2, HGO=1, EREFS=1, LP=0, IRCS=0
    MCG_C2 = MCG_C2_RANGE(2) | MCG_C2_HGO_MASK;// | MCG_C2_EREFS_MASK;

// after initialization of oscillator release latched state of oscillator and GPIO
    SIM_SCGC4 |= SIM_SCGC4_LLWU_MASK;
    LLWU_CS |= LLWU_CS_ACKISO_MASK;
    
// Select external oscilator and Reference Divider and clear IREFS to start ext osc
// CLKS=2, FRDIV=3, IREFS=0, IRCLKEN=0, IREFSTEN=0
  MCG_C1 = MCG_C1_CLKS(2) | MCG_C1_FRDIV(3);
    
  while (MCG_S & MCG_S_IREFST_MASK){}; // wait for Reference clock Status bit to clear

  while (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x2){}; // Wait for clock status bits to show clock source is ext ref clk

// Now in FBE

   MCG_C5 = MCG_C5_PRDIV(0x18);

  // Ensure MCG_C6 is at the reset default of 0. LOLIE disabled, PLL disabled, clk monitor disabled, PLL VCO divider is clear
   MCG_C6 = 0x0;

      // Set system options dividers
      //MCG=PLL, core = MCG, bus = MCG, FlexBus = MCG, Flash clock= MCG/2
      set_sys_dividers(0,0,0,1);
      // Set the VCO divider and enable the PLL for 48MHz, LOLIE=0, PLLS=1, CME=0, VDIV=0
      MCG_C6 = MCG_C6_PLLS_MASK; //VDIV = 0 (x24)

  while (!(MCG_S & MCG_S_PLLST_MASK)){}; // wait for PLL status bit to set

  while (!(MCG_S & MCG_S_LOCK_MASK)){}; // Wait for LOCK bit to set

// Now running PBE Mode

// Transition into PEE by setting CLKS to 0
// CLKS=0, FRDIV=3, IREFS=0, IRCLKEN=0, IREFSTEN=0
  MCG_C1 &= ~MCG_C1_CLKS_MASK;

// Wait for clock status bits to update
  while (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x3){};

// Now running PEE Mode

    return 0;
} //pll_init

/* EOF */


void ISR_Tracker (void)
{
  Fault = SCB_SHCSR;
   asm ("NOP");
}

__ramfunc void set_sys_dividers(unsigned int outdiv1, unsigned int outdiv2, unsigned int outdiv3, unsigned int outdiv4)
{
 /*
  * This routine must be placed in RAM. It is a workaround for errata e2448.
  * Flash prefetch must be disabled when the flash clock divider is changed.
  * This cannot be performed while executing out of flash.
  * There must be a short 
 after the clock dividers are changed before prefetch
  * can be re-enabled.
  */
  unsigned int temp_reg;
  unsigned char i;
  
  temp_reg = FMC_PFAPR; // store present value of FMC_PFAPR
  
  // set M0PFD through M7PFD to 1 to disable prefetch
  FMC_PFAPR |= FMC_PFAPR_M7PFD_MASK | FMC_PFAPR_M6PFD_MASK | FMC_PFAPR_M5PFD_MASK
             | FMC_PFAPR_M4PFD_MASK | FMC_PFAPR_M3PFD_MASK | FMC_PFAPR_M2PFD_MASK
             | FMC_PFAPR_M1PFD_MASK | FMC_PFAPR_M0PFD_MASK;
  
  // set clock dividers to desired value  
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(outdiv1) | SIM_CLKDIV1_OUTDIV2(outdiv2) 
              | SIM_CLKDIV1_OUTDIV3(outdiv3) | SIM_CLKDIV1_OUTDIV4(outdiv4);

  // wait for dividers to change
  for (i = 0 ; i < outdiv4 ; i++)
  {}
  
  FMC_PFAPR = temp_reg; // re-store original value of FMC_PFAPR
  
  return;
} // set_sys_dividers