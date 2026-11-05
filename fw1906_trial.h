#pragma once

// Opt-in trial for a strip expecting CW,WW,X,G,R,B rather than G,R,B,CW,WW,X.
// Retain NeoPixelBus pixel size/settings and invert the permutation on reads.
#ifdef WLED_FW1906_WHITE_FIRST_TRIAL
class WledFw1906TrialFeature : public NeoGrbcwxFeature {
public:
  static void applyPixelColor(uint8_t* pixels, uint16_t index, ColorObject color) {
    uint8_t* p = getPixelAddress(pixels, index);
    p[0] = color.CW; p[1] = color.WW; p[2] = 0;
    p[3] = color.G; p[4] = color.R; p[5] = color.B;
  }

  static ColorObject retrievePixelColor(const uint8_t* pixels, uint16_t index) {
    const uint8_t* p = getPixelAddress(pixels, index);
    return ColorObject(p[4], p[3], p[5], p[1], p[0]);
  }

  static ColorObject retrievePixelColor_P(PGM_VOID_P pixels, uint16_t index) {
    const uint8_t* p = getPixelAddress(reinterpret_cast<const uint8_t*>(pixels), index);
    return ColorObject(pgm_read_byte(p+4), pgm_read_byte(p+3), pgm_read_byte(p+5),
                       pgm_read_byte(p+1), pgm_read_byte(p));
  }
};
#else
using WledFw1906TrialFeature = NeoGrbcwxFeature;
#endif
