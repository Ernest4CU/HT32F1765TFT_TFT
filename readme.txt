/**
<PRE>

 @page Project_Template

 @verbatim
 * @file    project_template/IP/Example/readme.txt
 * @version V1.00
 * @date    07/26/2012
 * @brief   Description of project template.
 @endverbatim

@par Description

<PRE>
The project template includes project related files for Keil MDK-ARM, IAR EWARM, and CooCox CoIDE. It provides a
convenient way to create and configure projects for Holtek example codes.
</PRE>

@par Contents

  IDE/Tool Name       IDE Version(*1)      Project File        Template Folder
  ================    =================    ================    ===============================================
  IAR EWARM           EWARM   V6.20        Project.eww         project_template/IP/Example/EWARM/
  Keil MDK-ARM        MDK-ARM V4.21        Project.uvproj      project_template/IP/Example/MDK_ARM/
  SourceryG++Lite     MDK-ARM V4.21        Project.uvproj      project_template/IP/Example/SourceryG++Lite/
  CooCox CoIDE        CoIDE   V1.4.2       CoIDE_Template.cob  project_template/IP/Example/CoIDE_Template/

Note 1: The format of project files may not be compatible with different IDE versions. For the situation,
        users may need to create project files based on the IDE version being used.

@par Usage

<PRE>
For different IDEs, please copy the corresponding template folder into the path of example code.
For example, copy "project_template/IP/Example/MDK_ARM/" into "example/GPIO/InputOutput/".

For the CoIDE user, the folder name have to be modifed after above action to avoid used the same project name. 
For example, rename "example/GPIO/InputOutput/CoIDE_Template/" as 
"example/GPIO/InputOutput/CoIDE_InputOutput/". 

User can double click the CreatProject.bat file in each example folder to copy the folder automatically.  

After the copy is finished, double click on Project File to load the IDE. Follow the instruction of IDE to
build, download, and debug the example code. Refer to the Quick Start guides below for more information.

  "Keil MDK-ARM Quick Start for Holtek¡¦s HT32 Series Microcontrollers"
  "IAR EWARM Quick Start for Holtek¡¦s HT32 Series Microcontrollers"

For the example code which has special project setting, Holtek provides separate project related files
(on the path of the example). Users do not need to copy any template files to these examples.

</PRE>

</PRE>

 * <h2><center>Copyright (C) 2012 Holtek Semiconductor Inc. All rights reserved</center></h2>
 */
