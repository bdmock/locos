// Run on the Linux build host against the actual trial header.
// Minimal NeoPixelBus interface stub; full firmware build verifies integration.
#include <cstdlib>
#include <stdint.h>
typedef const void* PGM_VOID_P;
#define pgm_read_byte(p) (*(const uint8_t*)(p))
struct Color {
  uint8_t R,G,B,WW,CW;
  Color(uint8_t r=0,uint8_t g=0,uint8_t b=0,uint8_t w=0,uint8_t c=0):R(r),G(g),B(b),WW(w),CW(c){}
};
struct NeoGrbcwxFeature {
  using ColorObject = Color;
  static uint8_t* getPixelAddress(uint8_t* p,uint16_t i) { return p+6*i; }
  static const uint8_t* getPixelAddress(const uint8_t* p,uint16_t i) { return p+6*i; }
};
#define WLED_FW1906_WHITE_FIRST_TRIAL
#include "WLED/wled00/fw1906_trial.h"
void failure() { std::abort(); }
void verify() {
  uint8_t p[18] = {};
  WledFw1906TrialFeature::applyPixelColor(p,1,Color(11,22,33,44,55));
  if(p[6]!=55 || p[7]!=44 || p[8]!=0 || p[9]!=22 || p[10]!=11 || p[11]!=33) failure();
  for(int i=0;i<6;i++) if(p[i] || p[i+12]) failure();
  auto c = WledFw1906TrialFeature::retrievePixelColor(p,1);
  if(c.R!=11 || c.G!=22 || c.B!=33 || c.WW!=44 || c.CW!=55) failure();
  c = WledFw1906TrialFeature::retrievePixelColor_P(p,1);
  if(c.R!=11 || c.G!=22 || c.B!=33 || c.WW!=44 || c.CW!=55) failure();
  WledFw1906TrialFeature::applyPixelColor(p,1,Color());
  for(int i=0;i<18;i++) if(p[i]) failure();
}
int main() { verify(); return 0; }
