# arma3-macvsog-columbia-items
Arma3 MACV-SOG Columbia - Object and Procedure for object creation

This article will provide information on how to create a new arma 3 inventory object from scratch. From an idea into an item that has the shape we want, the weight we chose, the texture we desire and that is available as a mod in order to make it accessible for multiplayer missions.

---

## Special thanks

- <u>Lukinator</u> (SOG Discord): for helping me build this procedure. 
- <u>HorribleGoat</u> (Arma Discord): for input about adding actions on objects. 
- <u>Kay</u> (RT Columbia Discord): for the previous discussions about creating mods and scripting.

## Requirements

- Blender version 3.6 (versions higher have issues with Arma 3). 
  - With this plugin installed https://github.com/AlwarrenSidh/ArmAToolbox/releases/tag/v4.0.5
- GIMP http://www.gimp.org/
- Arma 3 Tools. 
- Access to https://paa.gruppe-adler.de/, else .paa images will need to be generated manually (explained later in the document).

---

## Table of contents
- [1. Setup](#1-setup)
- [2. P3D object creation through Blender](#2-p3d-object-creation-through-blender)
  - [2.1 Create 3D Object](#21-create-3d-object)
  - [2.2 Add custom texture](#22-add-custom-texture)
    - [2.2.1 Work locally on Blender to see how texture is looking](#221-work-locally-on-blender-to-see-how-texture-is-looking)
    - [2.2.2 Export texture to .paa](#222-export-texture-to-paa)
  - [2.3 Improve texture using maps](#23-Improve-texture-using-maps)
    - [2.3.1 Normal map (for depth)](#231-normal-map-for-depth)
    - [2.3.2 Ambient occlusion map (for shadows)](#232-ambient-occlusion-map-for-shadows)
    - [2.3.3 Specular map (for reflectiveness of the material)](#233-specular-map-for-reflectiveness-of-the-material)
    - [2.3.4 Bundle all maps in .rvmat file](#234-bundle-all-maps-in-rvmat-file)
  - [2.4 End result for data folder](#24-end-result-for-data-folder)
- [3. Blender P3D to Arma P3D through Object Builder](#3-blender-p3d-to-arma-p3d-through-object-builder)
  - [3.1 Detect object components](#31-detect-object-components)
  - [3.2 Add texture to Arma 3 object](#32-add-texture-to-arma-3-object)
- [4. Create an icon for our inventory object](#4-create-an-icon-for-our-inventory-object)
- [5. Create the configuration for the object](#5-create-the-configuration-for-the-object)
- [6. Import object into Arma 3 using Addon Builder](#6-import-object-into-arma-3-using-addon-builder)
- [7. Local testing through Addons](#7-local-testing-through-addons)
- [8. Create a public mod using Arma Tool Publisher](#8-create-a-public-mod-using-arma-tool-publisher)
- [9. Add custom actions on object](#9-add-custom-actions-on-object)

---

## 1. Setup

<details>
<summary>open section</summary>

- Create this folder and file structure anywhere on your computer (this will be our workspace).

![screenshot](/images/Setup/setup.PNG)

- In the above example, a sensor (a seismic sensor used by MACV SOG in order to monitor movement of NVA soldiers) is the new object I want to create. This will be our <u>MAIN folder</u>.
- <u>data folder</u> will contain the object textures, in .paa format (currently an empty folder).
- <u>Icons folder</u> will contain the icon for our object, in .paa format (currently an empty folder).
- <u>Objects folder</u> will contain the 3D object in .p3d format (currently an empty folder).
- <u>Config.cpp file</u> will contain the configuration for our object and will allow us to configure its weight, name, etc. (currently an empty file).

</details>

## 2. P3D object creation through Blender

<details>
<summary>2.1 Create 3D Object</summary>

## 2.1 Create 3D Object

- Create a 3D item in Blender that has the desired shape.
- At the end of the item creation, make sure it is a single 3D object (top right of blender) and that “Arma Object Property” is selected.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/create3DObject.PNG)

- Pressing CTRL + T will triangulate the 3D objects (make its faces only triangles) and remove any ngons (Arma does not want ngons).

</details>

<details>
<summary>2.2 Add custom texture</summary>

## 2.2 Add custom texture

<details>
<summary>2.2.1 Work locally on Blender to see how texture is looking</summary>

## 2.2.1 Work locally on Blender to see how texture is looking

- Create a UV map by selecting the object and clicking on “U”. Making an easy one to work with is sometimes tricky but adding some seams in Blender can help.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/addCustomTexture1.PNG)

- Then export the UV map as a .png (<u>object_uv_map.png</u>), then using any editing software, update the .png to have the texture you want and save it as a new .png (<u>object_texture.png</u>). Keep in mind that the resolution MUST be 512x512.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/addCustomTexture2.PNG)

- Go back to Blender, make sure your object has a default material (not empty) and open the “Shader Editor” (Shift + F3).
- Right click and add an “Image Texture” with as path, the path of the <u>object_texture.png</u>.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/addCustomTexture3.PNG)

- Then, if you go back to the 3D Viewport you will be able to see the object with the new texture.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/addCustomTexture4.PNG)

- Finally, export the 3D object and .p3d file and save it to a temporary location like “Downloads” or “Desktop”.
- N.B. The main purpose of adding texture in Blender is to visualise how it will look onto the object and make sure it is looking good.

</details>

<details>
<summary>2.2.2 Export texture to .paa</summary>

## 2.2.2 Export texture to .paa

- Go to https://paa.gruppe-adler.de/ and convert <u>object_texture.png</u> into a .paa (<u>object_texture.paa</u>).
  - Manual steps (if website is down):
    - Use the TexView 2 (Arma 3 Tools) to convert the .png into a .paa (Use ‘RGBA’ and in the other section use ‘DXT5’).
  - Save the generated <u>object_texture.paa</u> in <u>data folder</u>. This is important because when exporting as a mod, the path to the texture needs to follow this syntax:
    - “yourAddonName\data\yourTexture.paa”

![screenshot](/images/P3D%20object%20creation%20through%20Blender/addCustomTexture5.PNG)

</details>

</details>

<details>
<summary>2.3 Improve texture using maps</summary>

## 2.3 Improve texture using maps

- This is optional but will result in a more realistic looking object with roughness and texture instead of looking flat, glassy with our own texture.

<details>
<summary>2.3.1 Normal map (for depth)</summary>

## 2.3.1 Normal map (for depth)

- N.B. following the tutorial https://kcclemo.neocities.org/creating-height-and-normal-maps/ will work but I will be going over it in this document in case the website goes down.
- Open the texture <u>object_texture.png</u> (obtained in section 4.2.2) in GIMP.
- Select Image>Mode>Grayscale.
  - Pixels more black: low points. 
  - Pixel more white: high points.
- If needed, you can invert the colors using Colors>Invert.
- In the Levels dialog:

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps1.PNG)

  - Arrange the 3 triangles to correspond to the above picture.
- Now we can save the new picture (keep in mind that we need to have a resolution of 512x512) and this will give us our <u>detector_bump.png</u>.
- We need to convert this new png into a normal map. To do this, you can use the following website (if down, will need to find a tutorial on how to create normal map…) https://cpetry.github.io/NormalMap-Online/.
  - Drag and drop your detector_bump.png in the website, and uncheck “Displacement”, “AO” and “Specular”.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps2.PNG)

- Then below the middle picture, rename it to <u>detector_nohq</u> and save.
- Convert the .png into a .paa (see "2.2.2 Export texture to .paa").
- Save the generated <u>detector_nohq.paa</u> in the <u>data folder</u>.
- We now have our normal map <u>detector_nohq.paa</u> and it can be moved to the <u>data folder</u>.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps3.PNG)

</details>

<details>
<summary>2.3.2 Ambient occlusion map (for shadows)</summary>

## 2.3.2 Ambient occlusion map (for shadows)

- Blender can be used to generate the occlusion map.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps4.PNG)

- Go in the render view, with the following setup:
  - Render Engine: Cycle
  - Bake>Bake Type: Ambient Occlusion
- Select the object and click on the “Bake” button and this will give the following result. 

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps5.PNG)

- In the top left, click on image*>save as, and then save it as <u>detector_as.png</u>. 
- Convert the .png into a .paa (see "2.2.2 Export texture to .paa"). 
- Save the generated <u>detector_as.paa</u> in the <u>data folder</u>. 
- We now have our ambient occlusion map <u>detector_as.paa</u> and it can be moved to the <u>data folder</u>.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps6.PNG)

</details>

<details>
<summary>2.3.3 Specular map (for reflectiveness of the material)</summary>

## 2.3.3 Specular map (for reflectiveness of the material)

- N.B. The whitest will mean the more reflective a texture is. The blackest, the less reflective a texture is.
- To generate the Specular map, I used https://cpetry.github.io/NormalMap-Online/ and selected “Specular” (middle picture and top right) and reduced the strength in order to make the object blacker (less reflective).

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps7.PNG)

- Then below the middle picture, rename it to detector_smdi and save.
- Convert the .png into a .paa (see "2.2.2 Export texture to .paa").
- Save the generated <u>detector_smdi.paa</u> in the <u>data folder</u>.
- We now have our specular map <u>detector_smdi.paa</u> and it can be moved to the <u>data folder</u>.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps8.PNG)

</details>

<details>
<summary>2.3.4 Bundle all maps in .rvmat file</summary>

## 2.3.4 Bundle all maps in .rvmat file

- You can use the below “default” template and change the name of .paa files to suit your model.

    ```
    class StageTI
    {
        texture="#(argb,8,8,3)color(0,0,0,0)";
    };
    ambient[]={1,1,1,1};
    diffuse[]={1,1,1,1};
    forcedDiffuse[]={0,0,0,0};
    emmisive[] = {0,0,0,0};
    specular[] = {0.15,0.15,0.15,1};
    specularPower = 80;
    PixelShaderID = "Super";
    VertexShaderID = "Super";
    class Stage1
    {
        texture="detector\data\detector_nohq.paa";
        uvSource="tex";
        class uvTransform
        {
            aside[]={1,0,0};
            up[]={0,1,0};
            dir[]={0,0,0};
            pos[]={0,0,0};
        };
    };
    class Stage2
    {
        texture="#(argb,8,8,3)color(0.5,0.5,0.5,0.5,DT)";
        uvSource="tex";
        class uvTransform
        {
            aside[]={1,0,0};
            up[]={0,1,0};
            dir[]={0,0,0};
            pos[]={0,0,0};
        };
    };
    class Stage3
    {
        texture="#(argb,8,8,3)color(0,0,0,0,MC)";
        uvSource="tex";
        class uvTransform
        {
            aside[]={1,0,0};
            up[]={0,1,0};
            dir[]={0,0,0};
            pos[]={0,0,0};
        };
    };
    class Stage4
    {
        texture="detector\data\detetector_as.paa";
        uvSource="tex";
        class uvTransform
        {
            aside[]={1,0,0};
            up[]={0,1,0};
            dir[]={0,0,0};
            pos[]={0,0,0};
        };
    };
    class Stage5
    {
        texture="detector\data\detector_smdi.paa";
        uvSource="tex";
        class uvTransform
        {
            aside[]={1,0,0};
            up[]={0,1,0};
            dir[]={0,0,0};
            pos[]={0,0,0};
        };
    };
    class Stage6
    {
        texture="#(ai,32,128,1)fresnel(2.45,0.75)";
        uvSource="none";
    };
    class Stage7
    {
        texture="a3\data_f\env_co.tga";
        uvSource="tex";
        class uvTransform
        {
            aside[]={1,0,0};
            up[]={0,1,0};
            dir[]={0,0,0};
            pos[]={0,0,0};
        };
    };
    ```

- What is important here is to include the 3 .paa file we generated:
  - <u>detector_nohq.paa</u>
  - <u>detector_as.paa</u>
  - <u>detector_smdi.paa</u>
- N.B. with a path from the <u>MAIN folder</u> (ex: detector\data\detector_smdi.paa).

![screenshot](/images/P3D%20object%20creation%20through%20Blender/improveTextureUsingMaps9.PNG)

- We now have our <u>detector.rvmat</u> file.

</details>

</details>

<details>
<summary>2.4 End result for data folder</summary>

## 2.4 End result for data folder

- Add the end, you should have 5 files into the <u>data folder</u>.

![screenshot](/images/P3D%20object%20creation%20through%20Blender/endResultForDataFolder.PNG)

</details>

## 3. Blender P3D to Arma P3D through Object Builder

<details>
<summary>3.1 Detect object components</summary>

## 3.1 Detect object components

- Open the .p3d file previously exported with Arma 3 Object Builder (see Arma 3 Tools).
- Select the entire 3D object and go into “structure/topology/find components”. This will create the required components for Arma 3 objects.

</details>

<details>
<summary>3.2 Add texture to Arma 3 object</summary>

## 3.2 Add texture to Arma 3 object

- Go back to the Object Builder, select the object (all nodes) and click “E” to open the “Face Properties” menu.
  - In texture, select your .paa texture then click “Apply” and “Ok”.

![screenshot](/images/Blender%20P3D%20to%20Arma%20P3D%20through%20Object%20Builder/addTextureToArma3Object1.PNG)

- Then in the “material” path (below the “texture” path) put the path to the <u>detector.rvmat</u> (it must be under path “yourObject/data/yourObject.rvmat”)  then click “Apply” and “Ok”.

![screenshot](/images/Blender%20P3D%20to%20Arma%20P3D%20through%20Object%20Builder/addTextureToArma3Object2.PNG) 

- Save and export as .p3d and save it in the <u>Objects folder</u>.

</details>


## 4. Create an icon for our inventory object

<details>
<summary>open section</summary>

- Create a .png representing your objects (a print screen of blender can work).
- Resize it to be 512x512 pixels.
- Convert the .png into a .paa (see "2.2.2 Export texture to .paa").
- Move the generated .paa file into the Icons folder.
</details>

## 5. Create the configuration for the object

<details>
<summary>open section</summary>

- Open and edit the <u>config.cpp file</u> and paste the below content into it:

    ```
    class CfgPatches
    {
        class sensor //name of folder containing objects, icons and config.
        {
            units[]={};
            weapons[]={};
            requiredVersion=0.1;
            requiredAddons[]={"A3_Characters_F"};
        }
    }
    
    
    class CfgMagazines
    {
        class CA_Magazine;
        class colsog_inv_sensor: CA_Magazine
        {
            author = "Gerard";
            mass = 11;
            scope = 2;
            value = 1;
            displayName = "Seismic sensor";
            picture = "\sensor\icons\sensorIcon.paa";
            model = "\sensor\objects\sensorObj.p3d";
            type = 256;
            count = 1;
            initSpeed = 18;
            nameSound = "handgrenade";
            maxLeadSpeed = 6.94444;
            descriptionShort = "Seismic sensor";
            displayNameShort = "Seismic sensor";
        };
    };
    ```
- ‘Mass’ is the mass of your new object and actual in-game weight will be divided by 10 (ex: 11 mass in the configuration means 1,1 pound of mass in game).
- ‘Picture’ needs to point to the icon .paa previously generated (with path from <u>MAIN folder</u>).
- ‘Model’ needs to point to the icon .p3d previously generated (with path from <u>MAIN folder</u>).

</details>

## 6. Import object into Arma 3 using Addon Builder

<details>
<summary>open section</summary>

- Open the Addon Builder (Arma 3 Tools).
  - Addons source directory: path to <u>MAIN folder</u>.
  - Destination directory: Path to Arma 3 !Workshop.
- Toggle:
  - Clear temp folder.
  - Binarize.
    - Enable extended logging.
- Then you can click on PACK (bottom right).

![screenshot](/images/Import%20object%20into%20Arma%203%20using%20Addon%20Builder/addonBuilder.PNG)

- This will generate and save a .pbo file into the specified <u>folder in !Workshop</u>.

![screenshot](/images/Import%20object%20into%20Arma%203%20using%20Addon%20Builder/pbo.PNG)

</details>

## 7. Local testing through Addons

<details>
<summary>open section</summary>

- Copy the .pbo generated during the previous step and paste it directly into the Addons folder of Arma 3.

![screenshot](/images/Local%20testing%20through%20Addons/pbo.PNG)

- Restart Arma 3 (if it was previously launched), go into the Eden editor and now the object (sensor) will be visible in the arsenal under the magazine section (since in the configuration we are extending the magazine class).

![screenshot](/images/Local%20testing%20through%20Addons/arsenal.PNG)

- You can also run the following line in order to make it spawn into the inventory of the player:

    ```
    player addItem “colsog_inv_sensor”;
    ```

![screenshot](/images/Local%20testing%20through%20Addons/addItem.PNG)

</details>

## 8. Create a public mod using Arma Tool Publisher

<details>
<summary>open section</summary>

- We need to create a mod with our new object in order to make it available during multiplayer missions.
- Open Arma 3 Tool Publisher.
  - Mod content: path to the generated folder containing the .pbo file previously generated (see "6. Import object into Arma 3 using Addon Builder").
  - You can fill in other information such as tag, description, etc.
  - Agree with the Steamworks licence and click Publish (or Update if you are updating a previously published mod).

![screenshot](/images/Create%20a%20public%20mod%20using%20Arma%20Tool%20Publisher/publisher.PNG)

- Once successfully uploaded to the Steam workshop, your mod will be available for other to subscribe and then your new object will be able to be used in multiplayer missions.
- example: https://steamcommunity.com/sharedfiles/filedetails/?id=3332232289

![screenshot](/images/Create%20a%20public%20mod%20using%20Arma%20Tool%20Publisher/rtColumbiaItems.PNG)

</details>

## 9. Add custom actions on object

<details>
<summary>open section</summary>

- Adding it to the item directly is not ideal and really hard for several reasons I will not list here.
- Solution is to have a player action that is conditioned by the presence or not of the new object in the player’s inventory. Upon use, the object can be deleted from the player’s inventory, etc.
- Will add scripts adding behaviour to a new object we have created in https://github.com/gerard-sog/arma3-macvsog-columbia-scripts . (This part is WIP and currently nothing available, will try to have something for the 30th September 2024).

</details>