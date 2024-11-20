
#include <iostream>
#include <Tool.h>
#include "DataModel.h"

int main(int argc, char *argv[]) {

   WCTERawData p;
   BinaryStream input;
   input.Bopen(argv[1], READ, UNCOMPRESSED);
   bool crcok;
   uint8_t crcvalue;

   input >> p;

   std::cout << "read file " << std::endl;

   //std::cout << p.Print() << std::endl;
   
   // verify CRC
   for(int w=0; w<p.readout_windows.size(); w++) {
      for(int i=0; i<p.readout_windows[w].hkmpmt_hits.size(); i++) {
         p.readout_windows[w].hkmpmt_hits[i].Dump();
         printf("CRC from event: 0x%X\n", p.readout_windows[w].hkmpmt_hits[i].footer.GetCRC());
         crcok = p.readout_windows[w].hkmpmt_hits[i].VerifyCRC(&crcvalue);
         printf("CRC calc: 0x%X\n", crcvalue);
         printf("CRC ok: %d\n", crcok);
      }
   }

   printf("=======================================================\n");

   for(int w=0; w<p.readout_windows.size(); w++) {
      for(int i=0; i<p.readout_windows[w].hkmpmt_pps.size(); i++) {
         p.readout_windows[w].hkmpmt_pps[i].Dump();
         printf("CRC from event: 0x%X\n", p.readout_windows[w].hkmpmt_pps[i].GetCRC());
         crcok = p.readout_windows[w].hkmpmt_pps[i].VerifyCRC(&crcvalue);
         printf("CRC calc: 0x%X\n", crcvalue);
         printf("CRC ok: %d\n", crcok);
      }
   }

   return 0;

}
