_Copyright Frederik Trampenau All Rights Reserved._

# Squad Goals

Squad Goals is a project developed and owned by Frederik Trampenau.

## How To Get The Project
To get and open the project you have to...
1. Clone the repository
2. Right-click "SquadGoals-Client/SquadGoals.uproject"
3. Select "Generate Visual Studio project files"
4. Open the "SquadGoals-Client/SquadGoals.sln" solution
5. Rebuild the solution
6. Run the "SquadGoals" configuration in Debug mode

Done! This should now open the project in Unreal Engine.

## Tools & Tech Stack

### Unreal Engine Version
This project is developed using Unreal Engine version 5.3.2.

### IDE
There is no specific IDE that this project must be developed with. I personally tend to use JetBrains' Rider.

## Stages

The project's status is divided into different "stages" of development.
Every stage has its own resources (i.e. Backend, Remote Content/Assets, Balancing Data) so players are not affected by the development of the project.
For the "in-development" stages, this is also reflected in the Git branching structure to ensure increased safety in stages closer to release versions.

Here is an overview of the used stages and their branches (if they have one):
| Stage   | Branch  | Usage                                                                                                                                                 |
| ------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------- |
| DEV     | dev     | Current work-in-progress state developers are working on preparing the next main update.                                                              |
| QA      | qa      | Safer state of the project which should be ready for testing. Gets based on the dev branch now and then and is used to prepare the next release.      |
| LIVE    | -       | Safest state of the project, this is the version players have access to. It doesn't have a branch since we have release-version branches for it.      |

## Versioning

We have versions for the...
* Client
* Backend
* Balancing Data
* Content/Assets
  * Especially important for remote content (provided i.e. via a CDN)
  * There can also be separate versions for different groups of content (i.e. DLCs)

### The Game/Client Version

The game version will be split into `[Major]`.`[Minor]`.`[Revision]`_`[UniqueBuildId]`

Other versions (i.e. from the Backend or Balancing Data) will follow a similar structure but might be simplified.

## Git Structure

The Git repository should align with the following guidelines.

### The `main` Branch

The `main` branch was used initially to set up the project.
It was replaced by stage or release version-specific branches later on.
In rare cases it might be used to perform basic project setup or to update documentation (like this README.md file).

### Stage Branches

The stage branches follow the guidelines described in the "Stages" section above.

### Version Branches

Version branches are structured as follows:
`release/[ClientVersion]`
For example:
`release/1.7.0_12345`

## Git Style Guide

The style of Git commits should follow the "Conventional Commits" rules.

> [!IMPORTANT]
> Style Guide Website (summary): https://www.conventionalcommits.org/en/v1.0.0/#summary

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

> [!IMPORTANT]
> Marking the default assets with `_Default` might improve readability (i.e. `T_Bob_Default_D`).

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
