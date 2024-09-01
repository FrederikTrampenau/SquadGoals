_Copyright Frederik Trampenau All Rights Reserved._

# Squad Goals

Squad Goals is a project developed and owned by Frederik Trampenau.

## Client UE5 Project Style Guide

The style of the UE5 client project should follow the "ue5-style-guide" from "Allar".

> [!IMPORTANT]
> Style Guide GitRepo: https://github.com/Allar/ue5-style-guide

Example for the asset "Bob":

| Asset Type               | Asset Name    |
| ------------------------ | ------------- |
| Skeletal Mesh            | SK_Bob        |
| Material                 | M_Bob         |
| Texture (Diffuse/Albedo) | T_Bob_D       |
| Texture (Normal)         | T_Bob_N       |
| Texture (Evil Diffuse)   | T_Bob_Evil_D  |
| Blueprint                | BP_Bob        |

**Most Important Links**
* Assets
  * [Asset Naming Conventions](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#asset-name-modifiers)
  * [Content Directory Structure](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#2-content-directory-structure)
  * [Use Developers Folder For Local Testing](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#23-use-developers-folder-for-local-testing)
  * [All Map Files Belong In A Folder Called Maps](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#24-all-map-files-belong-in-a-folder-called-maps)
  * [Use A Core Folder For Critical Blueprints And Other Assets](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#25-use-a-core-folder-for-critical-blueprints-and-other-assets)
  * [Very Large Asset Sets Get Their Own Folder Layout](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#27-very-large-asset-sets-get-their-own-folder-layout)
* Blueprints
  * [Blueprints](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#3-blueprints)
  * [Blueprint Graphs](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#34-blueprint-graphs)
* [Levels / Map](https://github.com/Allar/ue5-style-guide?tab=readme-ov-file#6-levels--maps)

## C++ Style Guide

The C++ files should follow the Epic Games Coding Standard.

> [!IMPORTANT]
> Style Guide Website: https://dev.epicgames.com/documentation/en-us/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine

Furthermore, all source files (.h, .cpp, .xaml) should have the following copyright notice as the first line in the file:
> _// Copyright Frederik Trampenau All Rights Reserved._

## Git Style Guide

The style of Git commits should follow the "Conventional Commits" rules.

> [!IMPORTANT]
> Style Guide Website (summary): https://www.conventionalcommits.org/en/v1.0.0/#summary
