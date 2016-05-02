#ifndef UART_H
#define UART_H


#undef  HW_FLOW_CONTROL


#include "types.h"
#include "derivative.h" /* include peripheral declarations */
#include "user_config.h"
#include "RealTimerCounter.h"
#include "Wdt_kinetis.h"
#include "TWR_K50_UI.h"
#include "stdio.h"

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)
#define UART_MA1_REG(base)                       ((base)->MA1)
#define UART_MA2_REG(base)                       ((base)->MA2)
#define UART_C4_REG(base)                        ((base)->C4)
#define UART_C5_REG(base)                        ((base)->C5)
#define UART_ED_REG(base)                        ((base)->ED)
#define UART_MODEM_REG(base)                     ((base)->MODEM)
#define UART_IR_REG(base)                        ((base)->IR)
#define UART_PFIFO_REG(base)                     ((base)->PFIFO)
#define UART_CFIFO_REG(base)                     ((base)->CFIFO)
#define UART_SFIFO_REG(base)                     ((base)->SFIFO)
#define UART_TWFIFO_REG(base)                    ((base)->TWFIFO)
#define UART_TCFIFO_REG(base)                    ((base)->TCFIFO)
#define UART_RWFIFO_REG(base)                    ((base)->RWFIFO)
#define UART_RCFIFO_REG(base)                    ((base)->RCFIFO)
#define UART_C7816_REG(base)                     ((base)->C7816)
#define UART_IE7816_REG(base)                    ((base)->IE7816)
#define UART_IS7816_REG(base)                    ((base)->IS7816)
#define UART_WP7816_T_TYPE0_REG(base)            ((base)->WP7816_T_TYPE0)
#define UART_WP7816_T_TYPE1_REG(base)            ((base)->WP7816_T_TYPE1)
#define UART_WN7816_REG(base)                    ((base)->WN7816)
#define UART_WF7816_REG(base)                    ((base)->WF7816)
#define UART_ET7816_REG(base)                    ((base)->ET7816)
#define UART_TL7816_REG(base)                    ((base)->TL7816)

/**
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK)
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_MSBF_MASK                        0x20u
#define UART_S2_MSBF_SHIFT                       5
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_RT_MASK                           0xFFu
#define UART_D_RT_SHIFT                          0
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK)
/* MA1 Bit Fields */
#define UART_MA1_MA_MASK                         0xFFu
#define UART_MA1_MA_SHIFT                        0
#define UART_MA1_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA1_MA_SHIFT))&UART_MA1_MA_MASK)
/* MA2 Bit Fields */
#define UART_MA2_MA_MASK                         0xFFu
#define UART_MA2_MA_SHIFT                        0
#define UART_MA2_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA2_MA_SHIFT))&UART_MA2_MA_MASK)
/* C4 Bit Fields */
#define UART_C4_BRFA_MASK                        0x1Fu
#define UART_C4_BRFA_SHIFT                       0
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         0x20u
#define UART_C4_M10_SHIFT                        5
#define UART_C4_MAEN2_MASK                       0x40u
#define UART_C4_MAEN2_SHIFT                      6
#define UART_C4_MAEN1_MASK                       0x80u
#define UART_C4_MAEN1_SHIFT                      7
/* C5 Bit Fields */
#define UART_C5_RDMAS_MASK                       0x20u
#define UART_C5_RDMAS_SHIFT                      5
#define UART_C5_TDMAS_MASK                       0x80u
#define UART_C5_TDMAS_SHIFT                      7
/* ED Bit Fields */
#define UART_ED_PARITYE_MASK                     0x40u
#define UART_ED_PARITYE_SHIFT                    6
#define UART_ED_NOISY_MASK                       0x80u
#define UART_ED_NOISY_SHIFT                      7
/* MODEM Bit Fields */
#define UART_MODEM_TXCTSE_MASK                   0x1u
#define UART_MODEM_TXCTSE_SHIFT                  0
#define UART_MODEM_TXRTSE_MASK                   0x2u
#define UART_MODEM_TXRTSE_SHIFT                  1
#define UART_MODEM_TXRTSPOL_MASK                 0x4u
#define UART_MODEM_TXRTSPOL_SHIFT                2
#define UART_MODEM_RXRTSE_MASK                   0x8u
#define UART_MODEM_RXRTSE_SHIFT                  3
/* IR Bit Fields */
#define UART_IR_TNP_MASK                         0x3u
#define UART_IR_TNP_SHIFT                        0
#define UART_IR_TNP(x)                           (((uint8_t)(((uint8_t)(x))<<UART_IR_TNP_SHIFT))&UART_IR_TNP_MASK)
#define UART_IR_IREN_MASK                        0x4u
#define UART_IR_IREN_SHIFT                       2
/* PFIFO Bit Fields */
#define UART_PFIFO_RXFIFOSIZE_MASK               0x7u
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     0x8u
#define UART_PFIFO_RXFE_SHIFT                    3
#define UART_PFIFO_TXFIFOSIZE_MASK               0x70u
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     0x80u
#define UART_PFIFO_TXFE_SHIFT                    7
/* CFIFO Bit Fields */
#define UART_CFIFO_RXUFE_MASK                    0x1u
#define UART_CFIFO_RXUFE_SHIFT                   0
#define UART_CFIFO_TXOFE_MASK                    0x2u
#define UART_CFIFO_TXOFE_SHIFT                   1
#define UART_CFIFO_RXFLUSH_MASK                  0x40u
#define UART_CFIFO_RXFLUSH_SHIFT                 6
#define UART_CFIFO_TXFLUSH_MASK                  0x80u
#define UART_CFIFO_TXFLUSH_SHIFT                 7
/* SFIFO Bit Fields */
#define UART_SFIFO_RXUF_MASK                     0x1u
#define UART_SFIFO_RXUF_SHIFT                    0
#define UART_SFIFO_TXOF_MASK                     0x2u
#define UART_SFIFO_TXOF_SHIFT                    1
#define UART_SFIFO_RXEMPT_MASK                   0x40u
#define UART_SFIFO_RXEMPT_SHIFT                  6
#define UART_SFIFO_TXEMPT_MASK                   0x80u
#define UART_SFIFO_TXEMPT_SHIFT                  7
/* TWFIFO Bit Fields */
#define UART_TWFIFO_TXWATER_MASK                 0xFFu
#define UART_TWFIFO_TXWATER_SHIFT                0
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK)
/* TCFIFO Bit Fields */
#define UART_TCFIFO_TXCOUNT_MASK                 0xFFu
#define UART_TCFIFO_TXCOUNT_SHIFT                0
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK)
/* RWFIFO Bit Fields */
#define UART_RWFIFO_RXWATER_MASK                 0xFFu
#define UART_RWFIFO_RXWATER_SHIFT                0
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK)
/* RCFIFO Bit Fields */
#define UART_RCFIFO_RXCOUNT_MASK                 0xFFu
#define UART_RCFIFO_RXCOUNT_SHIFT                0
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK)
/* C7816 Bit Fields */
#define UART_C7816_ISO_7816E_MASK                0x1u
#define UART_C7816_ISO_7816E_SHIFT               0
#define UART_C7816_TTYPE_MASK                    0x2u
#define UART_C7816_TTYPE_SHIFT                   1
#define UART_C7816_INIT_MASK                     0x4u
#define UART_C7816_INIT_SHIFT                    2
#define UART_C7816_ANACK_MASK                    0x8u
#define UART_C7816_ANACK_SHIFT                   3
#define UART_C7816_ONACK_MASK                    0x10u
#define UART_C7816_ONACK_SHIFT                   4
/* IE7816 Bit Fields */
#define UART_IE7816_RXTE_MASK                    0x1u
#define UART_IE7816_RXTE_SHIFT                   0
#define UART_IE7816_TXTE_MASK                    0x2u
#define UART_IE7816_TXTE_SHIFT                   1
#define UART_IE7816_GTVE_MASK                    0x4u
#define UART_IE7816_GTVE_SHIFT                   2
#define UART_IE7816_INITDE_MASK                  0x10u
#define UART_IE7816_INITDE_SHIFT                 4
#define UART_IE7816_BWTE_MASK                    0x20u
#define UART_IE7816_BWTE_SHIFT                   5
#define UART_IE7816_CWTE_MASK                    0x40u
#define UART_IE7816_CWTE_SHIFT                   6
#define UART_IE7816_WTE_MASK                     0x80u
#define UART_IE7816_WTE_SHIFT                    7
/* IS7816 Bit Fields */
#define UART_IS7816_RXT_MASK                     0x1u
#define UART_IS7816_RXT_SHIFT                    0
#define UART_IS7816_TXT_MASK                     0x2u
#define UART_IS7816_TXT_SHIFT                    1
#define UART_IS7816_GTV_MASK                     0x4u
#define UART_IS7816_GTV_SHIFT                    2
#define UART_IS7816_INITD_MASK                   0x10u
#define UART_IS7816_INITD_SHIFT                  4
#define UART_IS7816_BWT_MASK                     0x20u
#define UART_IS7816_BWT_SHIFT                    5
#define UART_IS7816_CWT_MASK                     0x40u
#define UART_IS7816_CWT_SHIFT                    6
#define UART_IS7816_WT_MASK                      0x80u
#define UART_IS7816_WT_SHIFT                     7
/* WP7816_T_TYPE0 Bit Fields */
#define UART_WP7816_T_TYPE0_WI_MASK              0xFFu
#define UART_WP7816_T_TYPE0_WI_SHIFT             0
#define UART_WP7816_T_TYPE0_WI(x)                (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE0_WI_SHIFT))&UART_WP7816_T_TYPE0_WI_MASK)
/* WP7816_T_TYPE1 Bit Fields */
#define UART_WP7816_T_TYPE1_BWI_MASK             0xFu
#define UART_WP7816_T_TYPE1_BWI_SHIFT            0
#define UART_WP7816_T_TYPE1_BWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_BWI_SHIFT))&UART_WP7816_T_TYPE1_BWI_MASK)
#define UART_WP7816_T_TYPE1_CWI_MASK             0xF0u
#define UART_WP7816_T_TYPE1_CWI_SHIFT            4
#define UART_WP7816_T_TYPE1_CWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_CWI_SHIFT))&UART_WP7816_T_TYPE1_CWI_MASK)
/* WN7816 Bit Fields */
#define UART_WN7816_GTN_MASK                     0xFFu
#define UART_WN7816_GTN_SHIFT                    0
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK)
/* WF7816 Bit Fields */
#define UART_WF7816_GTFD_MASK                    0xFFu
#define UART_WF7816_GTFD_SHIFT                   0
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK)
/* ET7816 Bit Fields */
#define UART_ET7816_RXTHRESHOLD_MASK             0xFu
#define UART_ET7816_RXTHRESHOLD_SHIFT            0
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK)
#define UART_ET7816_TXTHRESHOLD_MASK             0xF0u
#define UART_ET7816_TXTHRESHOLD_SHIFT            4
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK)
/* TL7816 Bit Fields */
#define UART_TL7816_TLEN_MASK                    0xFFu
#define UART_TL7816_TLEN_SHIFT                   0
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK)

/**
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base pointer */
#define UART0_BASE_PTR                           ((UART_MemMapPtr)0x4006A000u)
/** Peripheral UART1 base pointer */
#define UART1_BASE_PTR                           ((UART_MemMapPtr)0x4006B000u)
/** Peripheral UART2 base pointer */
#define UART2_BASE_PTR                           ((UART_MemMapPtr)0x4006C000u)
/** Peripheral UART3 base pointer */
#define UART3_BASE_PTR                           ((UART_MemMapPtr)0x4006D000u)
/** Peripheral UART4 base pointer */
#define UART4_BASE_PTR                           ((UART_MemMapPtr)0x400EA000u)
/** Peripheral UART5 base pointer */
#define UART5_BASE_PTR                           ((UART_MemMapPtr)0x400EB000u)

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0_BASE_PTR)
#define UART0_BDL                                UART_BDL_REG(UART0_BASE_PTR)
#define UART0_C1                                 UART_C1_REG(UART0_BASE_PTR)
#define UART0_C2                                 UART_C2_REG(UART0_BASE_PTR)
#define UART0_S1                                 UART_S1_REG(UART0_BASE_PTR)
#define UART0_S2                                 UART_S2_REG(UART0_BASE_PTR)
#define UART0_C3                                 UART_C3_REG(UART0_BASE_PTR)
#define UART0_D                                  UART_D_REG(UART0_BASE_PTR)
#define UART0_MA1                                UART_MA1_REG(UART0_BASE_PTR)
#define UART0_MA2                                UART_MA2_REG(UART0_BASE_PTR)
#define UART0_C4                                 UART_C4_REG(UART0_BASE_PTR)
#define UART0_C5                                 UART_C5_REG(UART0_BASE_PTR)
#define UART0_ED                                 UART_ED_REG(UART0_BASE_PTR)
#define UART0_MODEM                              UART_MODEM_REG(UART0_BASE_PTR)
#define UART0_IR                                 UART_IR_REG(UART0_BASE_PTR)
#define UART0_PFIFO                              UART_PFIFO_REG(UART0_BASE_PTR)
#define UART0_CFIFO                              UART_CFIFO_REG(UART0_BASE_PTR)
#define UART0_SFIFO                              UART_SFIFO_REG(UART0_BASE_PTR)
#define UART0_TWFIFO                             UART_TWFIFO_REG(UART0_BASE_PTR)
#define UART0_TCFIFO                             UART_TCFIFO_REG(UART0_BASE_PTR)
#define UART0_RWFIFO                             UART_RWFIFO_REG(UART0_BASE_PTR)
#define UART0_RCFIFO                             UART_RCFIFO_REG(UART0_BASE_PTR)
#define UART0_C7816                              UART_C7816_REG(UART0_BASE_PTR)
#define UART0_IE7816                             UART_IE7816_REG(UART0_BASE_PTR)
#define UART0_IS7816                             UART_IS7816_REG(UART0_BASE_PTR)
#define UART0_WP7816T0                           UART_WP7816_T_TYPE0_REG(UART0_BASE_PTR)
#define UART0_WP7816T1                           UART_WP7816_T_TYPE1_REG(UART0_BASE_PTR)
#define UART0_WN7816                             UART_WN7816_REG(UART0_BASE_PTR)
#define UART0_WF7816                             UART_WF7816_REG(UART0_BASE_PTR)
#define UART0_ET7816                             UART_ET7816_REG(UART0_BASE_PTR)
#define UART0_TL7816                             UART_TL7816_REG(UART0_BASE_PTR)
/* UART1 */
#define UART1_BDH                                UART_BDH_REG(UART1_BASE_PTR)
#define UART1_BDL                                UART_BDL_REG(UART1_BASE_PTR)
#define UART1_C1                                 UART_C1_REG(UART1_BASE_PTR)
#define UART1_C2                                 UART_C2_REG(UART1_BASE_PTR)
#define UART1_S1                                 UART_S1_REG(UART1_BASE_PTR)
#define UART1_S2                                 UART_S2_REG(UART1_BASE_PTR)
#define UART1_C3                                 UART_C3_REG(UART1_BASE_PTR)
#define UART1_D                                  UART_D_REG(UART1_BASE_PTR)
#define UART1_MA1                                UART_MA1_REG(UART1_BASE_PTR)
#define UART1_MA2                                UART_MA2_REG(UART1_BASE_PTR)
#define UART1_C4                                 UART_C4_REG(UART1_BASE_PTR)
#define UART1_C5                                 UART_C5_REG(UART1_BASE_PTR)
#define UART1_ED                                 UART_ED_REG(UART1_BASE_PTR)
#define UART1_MODEM                              UART_MODEM_REG(UART1_BASE_PTR)
#define UART1_IR                                 UART_IR_REG(UART1_BASE_PTR)
#define UART1_PFIFO                              UART_PFIFO_REG(UART1_BASE_PTR)
#define UART1_CFIFO                              UART_CFIFO_REG(UART1_BASE_PTR)
#define UART1_SFIFO                              UART_SFIFO_REG(UART1_BASE_PTR)
#define UART1_TWFIFO                             UART_TWFIFO_REG(UART1_BASE_PTR)
#define UART1_TCFIFO                             UART_TCFIFO_REG(UART1_BASE_PTR)
#define UART1_RWFIFO                             UART_RWFIFO_REG(UART1_BASE_PTR)
#define UART1_RCFIFO                             UART_RCFIFO_REG(UART1_BASE_PTR)
/* UART2 */
#define UART2_BDH                                UART_BDH_REG(UART2_BASE_PTR)
#define UART2_BDL                                UART_BDL_REG(UART2_BASE_PTR)
#define UART2_C1                                 UART_C1_REG(UART2_BASE_PTR)
#define UART2_C2                                 UART_C2_REG(UART2_BASE_PTR)
#define UART2_S1                                 UART_S1_REG(UART2_BASE_PTR)
#define UART2_S2                                 UART_S2_REG(UART2_BASE_PTR)
#define UART2_C3                                 UART_C3_REG(UART2_BASE_PTR)
#define UART2_D                                  UART_D_REG(UART2_BASE_PTR)
#define UART2_MA1                                UART_MA1_REG(UART2_BASE_PTR)
#define UART2_MA2                                UART_MA2_REG(UART2_BASE_PTR)
#define UART2_C4                                 UART_C4_REG(UART2_BASE_PTR)
#define UART2_C5                                 UART_C5_REG(UART2_BASE_PTR)
#define UART2_ED                                 UART_ED_REG(UART2_BASE_PTR)
#define UART2_MODEM                              UART_MODEM_REG(UART2_BASE_PTR)
#define UART2_IR                                 UART_IR_REG(UART2_BASE_PTR)
#define UART2_PFIFO                              UART_PFIFO_REG(UART2_BASE_PTR)
#define UART2_CFIFO                              UART_CFIFO_REG(UART2_BASE_PTR)
#define UART2_SFIFO                              UART_SFIFO_REG(UART2_BASE_PTR)
#define UART2_TWFIFO                             UART_TWFIFO_REG(UART2_BASE_PTR)
#define UART2_TCFIFO                             UART_TCFIFO_REG(UART2_BASE_PTR)
#define UART2_RWFIFO                             UART_RWFIFO_REG(UART2_BASE_PTR)
#define UART2_RCFIFO                             UART_RCFIFO_REG(UART2_BASE_PTR)
/* UART3 */
#define UART3_BDH                                UART_BDH_REG(UART3_BASE_PTR)
#define UART3_BDL                                UART_BDL_REG(UART3_BASE_PTR)
#define UART3_C1                                 UART_C1_REG(UART3_BASE_PTR)
#define UART3_C2                                 UART_C2_REG(UART3_BASE_PTR)
#define UART3_S1                                 UART_S1_REG(UART3_BASE_PTR)
#define UART3_S2                                 UART_S2_REG(UART3_BASE_PTR)
#define UART3_C3                                 UART_C3_REG(UART3_BASE_PTR)
#define UART3_D                                  UART_D_REG(UART3_BASE_PTR)
#define UART3_MA1                                UART_MA1_REG(UART3_BASE_PTR)
#define UART3_MA2                                UART_MA2_REG(UART3_BASE_PTR)
#define UART3_C4                                 UART_C4_REG(UART3_BASE_PTR)
#define UART3_C5                                 UART_C5_REG(UART3_BASE_PTR)
#define UART3_ED                                 UART_ED_REG(UART3_BASE_PTR)
#define UART3_MODEM                              UART_MODEM_REG(UART3_BASE_PTR)
#define UART3_IR                                 UART_IR_REG(UART3_BASE_PTR)
#define UART3_PFIFO                              UART_PFIFO_REG(UART3_BASE_PTR)
#define UART3_CFIFO                              UART_CFIFO_REG(UART3_BASE_PTR)
#define UART3_SFIFO                              UART_SFIFO_REG(UART3_BASE_PTR)
#define UART3_TWFIFO                             UART_TWFIFO_REG(UART3_BASE_PTR)
#define UART3_TCFIFO                             UART_TCFIFO_REG(UART3_BASE_PTR)
#define UART3_RWFIFO                             UART_RWFIFO_REG(UART3_BASE_PTR)
#define UART3_RCFIFO                             UART_RCFIFO_REG(UART3_BASE_PTR)
/* UART4 */
#define UART4_BDH                                UART_BDH_REG(UART4_BASE_PTR)
#define UART4_BDL                                UART_BDL_REG(UART4_BASE_PTR)
#define UART4_C1                                 UART_C1_REG(UART4_BASE_PTR)
#define UART4_C2                                 UART_C2_REG(UART4_BASE_PTR)
#define UART4_S1                                 UART_S1_REG(UART4_BASE_PTR)
#define UART4_S2                                 UART_S2_REG(UART4_BASE_PTR)
#define UART4_C3                                 UART_C3_REG(UART4_BASE_PTR)
#define UART4_D                                  UART_D_REG(UART4_BASE_PTR)
#define UART4_MA1                                UART_MA1_REG(UART4_BASE_PTR)
#define UART4_MA2                                UART_MA2_REG(UART4_BASE_PTR)
#define UART4_C4                                 UART_C4_REG(UART4_BASE_PTR)
#define UART4_C5                                 UART_C5_REG(UART4_BASE_PTR)
#define UART4_ED                                 UART_ED_REG(UART4_BASE_PTR)
#define UART4_MODEM                              UART_MODEM_REG(UART4_BASE_PTR)
#define UART4_IR                                 UART_IR_REG(UART4_BASE_PTR)
#define UART4_PFIFO                              UART_PFIFO_REG(UART4_BASE_PTR)
#define UART4_CFIFO                              UART_CFIFO_REG(UART4_BASE_PTR)
#define UART4_SFIFO                              UART_SFIFO_REG(UART4_BASE_PTR)
#define UART4_TWFIFO                             UART_TWFIFO_REG(UART4_BASE_PTR)
#define UART4_TCFIFO                             UART_TCFIFO_REG(UART4_BASE_PTR)
#define UART4_RWFIFO                             UART_RWFIFO_REG(UART4_BASE_PTR)
#define UART4_RCFIFO                             UART_RCFIFO_REG(UART4_BASE_PTR)
/* UART5 */
#define UART5_BDH                                UART_BDH_REG(UART5_BASE_PTR)
#define UART5_BDL                                UART_BDL_REG(UART5_BASE_PTR)
#define UART5_C1                                 UART_C1_REG(UART5_BASE_PTR)
#define UART5_C2                                 UART_C2_REG(UART5_BASE_PTR)
#define UART5_S1                                 UART_S1_REG(UART5_BASE_PTR)
#define UART5_S2                                 UART_S2_REG(UART5_BASE_PTR)
#define UART5_C3                                 UART_C3_REG(UART5_BASE_PTR)
#define UART5_D                                  UART_D_REG(UART5_BASE_PTR)
#define UART5_MA1                                UART_MA1_REG(UART5_BASE_PTR)
#define UART5_MA2                                UART_MA2_REG(UART5_BASE_PTR)
#define UART5_C4                                 UART_C4_REG(UART5_BASE_PTR)
#define UART5_C5                                 UART_C5_REG(UART5_BASE_PTR)
#define UART5_ED                                 UART_ED_REG(UART5_BASE_PTR)
#define UART5_MODEM                              UART_MODEM_REG(UART5_BASE_PTR)
#define UART5_IR                                 UART_IR_REG(UART5_BASE_PTR)
#define UART5_PFIFO                              UART_PFIFO_REG(UART5_BASE_PTR)
#define UART5_CFIFO                              UART_CFIFO_REG(UART5_BASE_PTR)
#define UART5_SFIFO                              UART_SFIFO_REG(UART5_BASE_PTR)
#define UART5_TWFIFO                             UART_TWFIFO_REG(UART5_BASE_PTR)
#define UART5_TCFIFO                             UART_TCFIFO_REG(UART5_BASE_PTR)
#define UART5_RWFIFO                             UART_RWFIFO_REG(UART5_BASE_PTR)
#define UART5_RCFIFO                             UART_RCFIFO_REG(UART5_BASE_PTR)

/**
 * @}
 */ /* end of group UART_Register_Accessor_Macros */

/***********************************************************************/
/*
 * The basic data types
 */
typedef unsigned char		uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int	uint32; /* 32 bits */

typedef char			    int8;   /*  8 bits */
typedef short int	        int16;  /* 16 bits */
typedef int		            int32;  /* 32 bits */

typedef volatile int8		vint8;  /*  8 bits */
typedef volatile int16		vint16; /* 16 bits */
typedef volatile int32		vint32; /* 32 bits */

typedef volatile uint8		vuint8;  /*  8 bits */
typedef volatile uint16		vuint16; /* 16 bits */
typedef volatile uint32		vuint32; /* 32 bits */

void uart_putchar (UART_MemMapPtr channel, char ch);
void uart_init (UART_MemMapPtr uartch, int sysclk, int baud);
char uart_getchar (UART_MemMapPtr channel);


#endif