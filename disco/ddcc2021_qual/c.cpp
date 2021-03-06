#include <bits/stdc++.h>
using namespace std;

using I = string;
using O = string;

// v>^<
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

O solve(const I& input) {
  vector a(20, vector<int>(20));

  for (int i = 0; i < input.size(); i++) {
    int y, x, c = 0;
    if ('A' <= input[i] && input[i] <= 'Z') x = input[i] - 'A', c = 1;
    if ('a' <= input[i] && input[i] <= 'z') x = input[i] - 'a', c = 2;
    if (!c) continue;

    if ('0' <= input[i + 2] && input[i + 2] <= '9') {
      y = 10 * (input[i + 1] - '0') + (input[i + 2] - '0') - 1;
      i += 2;
    } else {
      y = (input[i + 1] - '0') - 1;
      i += 1;
    }

    a[y][x] = c;
  }

  string r;
  for (int y0 = 0; y0 < 10; y0++) {
    int y = y0, x = 0, d = 1;
    while (true) {
      if (a[y][x] == 1) {
        d = 3 - d;
      } else if (a[y][x] == 2) {
        d = d - d % 2 + (1 - d % 2);
      }
      a[y][x] = 0;
      int y2 = y + dy[d];
      int x2 = x + dx[d];
      if (!(unsigned(y2) < 20 && unsigned(x2) < 20)) {
        if (y0 == 9) r = string(1, 'A' + x) + to_string(y + 1);
        break;
      }
      y = y2;
      x = x2;
    }
  }
  return r;
}

int main() {
  vector<O> r;

  // r.push_back(solve("m10F16M16f20h20"));
  // r.push_back(solve("a1A2E3J4b5C6b7k8C9T10q11n12l13F14l15M16I17h18j19m20"));
  // r.push_back(
  //     solve("c1f1Q1r1t1b2F2G2R2t2G3h3I3m3N3a4c4D4g4t4p5q5R5S5t5A6c6i6L6S6b7E7F7l7s7K8n8P8q8r8c9d9F9H9i9A10G10I10o10T10l"
  //           "11M11n11p11s11i12M12n12O12t12B13c13E13i13R13d14e14h14m14T14A15e15F15o15P15B16E16i16N16o16A17B17G17h17J17F1"
  //           "8g18K18L18m18A19C19l19n19R19b20D20J20n20R20"));

  r.push_back(
      solve("E1h1I1K1l1o1p1Q1R1T1A2E2F2k2l2n2o2r2S2t2B3C3D3E3L3M3N3O3Q3R3a4C4f4g4H4i4J4k4O4S4d5E5F5g5I5m5N5O5R5S5C6E6h6"
            "n6O6p6Q6R6s6t6a7d7f7j7K7P7Q7r7S7T7A8b8C8D8E8F8g8l8M8o8A9c9d9e9f9h9J9k9N9t9C10D10e10f10G10i10J10K10n10s10a1"
            "1C11D11f11j11l11p11q11r11S11A12c12D12e12F12h12K12L12O12p12d13E13f13K13l13P13Q13R13s13t13B14C14D14H14m14o14"
            "Q14r14S14T14H15I15J15k15l15m15N15p15r15S15B16h16i16J16K16n16o16p16R16s16k17L17M17N17o17p17q17R17S17T17a18C"
            "18D18E18f18h18i18J18m18o18b19e19F19G19J19k19L19p19q19r19A20b20c20d20k20L20Q20R20S20T20"));
  r.push_back(
      solve("e1i1j1M1N1o1P1Q1R1s1a2D2F2g2i2J2k2N2o2R2F3H3I3j3K3L3O3R3S3t3b4d4f4G4H4N4O4q4R4S4c5D5E5F5G5i5M5n5Q5R5a6B6c6"
            "k6n6O6p6Q6r6S6A7B7c7D7E7F7P7Q7r7t7e8F8G8k8l8M8N8r8s8T8a9d9h9i9J9k9l9m9R9t9b10C10E10H10i10m10N10P10q10S10a1"
            "1B11C11d11e11f11g11J11M11O11b12d12E12f12G12H12i12k12L12r12b13d13e13g13h13I13k13m13n13q13E14F14i14k14M14N14"
            "o14p14q14r14c15e15F15H15M15N15O15q15R15T15a16B16f16G16h16M16n16o16Q16R16a17B17C17E17h17I17j17l17O17r17E18F"
            "18h18I18J18M18n18O18R18s18d19F19g19h19K19l19M19r19S19t19B20C20D20i20J20K20l20M20O20T20"));
  r.push_back(
      solve("A1B1c1D1e1F1g1H1O1Q1A2b2C2E2G2H2I2o2R2s2a3B3C3e3g3m3q3R3s3T3e4H4I4J4K4l4m4n4s4t4h5j5k5l5m5N5O5p5q5S5a6c6D6"
            "E6k6l6m6P6q6r6A7D7g7H7k7L7P7Q7r7T7C8D8f8n8o8P8Q8r8s8T8A9b9d9E9F9G9H9N9p9R9c10d10E10G10N10p10q10r10s10T10i1"
            "1J11K11l11m11N11O11R11S11T11A12b12c12H12i12K12l12m12n12O12c13d13e13F13G13J13K13N13q13R13B14c14g14i14K14l14"
            "m14n14o14q14a15B15c15d15h15M15n15o15P15S15C16E16j16k16L16n16O16P16Q16t16a17b17C17E17h17I17J17O17R17T17d18f"
            "18J18k18L18M18N18P18q18T18c19d19e19f19J19K19M19q19R19T19A20B20d20k20l20M20N20R20s20T20"));

  for (int i = 0; i < r.size(); i++) cout << r[i] << "\n,"[i < r.size() - 1];
}
