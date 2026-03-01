# 🔬 BeamScan Simulation Results

**Author:** Paula  
**Description:** Sensitivity study: Detecting thin lead (Pb) veins within a quartz (SiO2) matrix using Multiple Coulomb Scattering (MCS).  
**Generated:** 2026-03-01 15:48 UTC  
**Method:** Highland formula (analytical)

## Beam Settings
- Particle: `e-`
- Momenta: [2.0, 5.0, 7.0] GeV/c
- Events requested: 25,000

## Predictions

| Material | p (GeV/c) | θ₀ (mrad) | ΔE (MeV) | X₀ (cm) | Thickness |
|----------|-----------|-----------|----------|---------|----------|
| SiO2 | 2.0 | **1.755** | 4.4 | 12.29 | 10.0 mm |
| SiO2 | 5.0 | **0.702** | 4.4 | 12.29 | 10.0 mm |
| SiO2 | 7.0 | **0.501** | 4.4 | 12.29 | 10.0 mm |
| SiO2_Pb_0.1mm | 2.0 | **0.769** | 0.2 | 0.561 | 0.1 mm |
| SiO2_Pb_0.1mm | 5.0 | **0.308** | 0.2 | 0.561 | 0.1 mm |
| SiO2_Pb_0.1mm | 7.0 | **0.220** | 0.2 | 0.561 | 0.1 mm |
| SiO2_Pb_0.5mm | 2.0 | **1.844** | 1.1 | 0.561 | 0.5 mm |
| SiO2_Pb_0.5mm | 5.0 | **0.737** | 1.1 | 0.561 | 0.5 mm |
| SiO2_Pb_0.5mm | 7.0 | **0.527** | 1.1 | 0.561 | 0.5 mm |
| SiO2_Pb_1.0mm | 2.0 | **2.683** | 2.3 | 0.561 | 1.0 mm |
| SiO2_Pb_1.0mm | 5.0 | **1.073** | 2.3 | 0.561 | 1.0 mm |
| SiO2_Pb_1.0mm | 7.0 | **0.767** | 2.3 | 0.561 | 1.0 mm |

## Discrimination Power (at 2.0 GeV/c)

Events needed for 3σ separation:

| | SiO2 | SiO2_Pb_0.1mm | SiO2_Pb_0.5mm | SiO2_Pb_1.0mm |
|---|---|---|---|---|
| **SiO2** | — | ✅ 30 | ⚠️ 7,391 | ✅ 103 |
| **SiO2_Pb_0.1mm** | ✅ 30 | — | ✅ 27 | ✅ 15 |
| **SiO2_Pb_0.5mm** | ⚠️ 7,391 | ✅ 27 | — | ✅ 131 |
| **SiO2_Pb_1.0mm** | ✅ 103 | ✅ 15 | ✅ 131 | — |

✅ Easy (<5k events) | ⚠️ Moderate (5k–100k) | ❌ Impractical (>100k)

## Figures

![distributions.png](distributions.png)

![classification.png](classification.png)


---
*Generated automatically by BeamScan Highland Calculator*
