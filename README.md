## Embedded C programming
C is a programming language designed by Dennis Ritchie at Bell Labs. C is very widely used, straightforward, and can be compiled to a number of platforms and operating systems. C is an imperative language, with a small number of keywords and a large number of mathematical operators. I included programming libraries,guides etc..

## Motivation
These program are meant for helping others who want to learn c programming from basics and also help them understand certain coding techniques and ideas.

## Build status
Build status of continus integration i.e. travis, appveyor etc. Ex. - 

[![Build Status](https://travis-ci.org/akashnimare/foco.svg?branch=master)](https://travis-ci.org/akashnimare/foco)
[![Windows Build Status](https://ci.appveyor.com/api/projects/status/github/akashnimare/foco?branch=master&svg=true)](https://ci.appveyor.com/project/akashnimare/foco/branch/master)

## Code style
If you're using any code style like xo, standard etc. That will help others while contributing to your project. Ex. -

[![js-standard-style](https://img.shields.io/badge/code%20style-standard-brightgreen.svg?style=flat)](https://github.com/feross/standard)
 
## Screenshots
Include logo/demo screenshot etc.

## Tech/framework used
Ex. -

<b>Built with</b>
- [Electron](https://electron.atom.io)

## Features
What makes your project stand out?

## Code Example
Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.

## Installation

Install Eclipse Oxygen IDE on Ubuntu 16.04 through terminal in ubuntu

Step 1: Install Java JDK8
Run the commands below

>sudo add-apt-repository ppa:webupd8team/java

After running the commands above, you should see a prompt to accept the PPA key onto Ubuntu… accept and continue

Now that the PPA repository has been added to Ubuntu, run the commands below to download Oracle Java 9 installer…. the installer should install the latest Java JDK 9 on your Ubuntu machines.

>sudo apt update
>sudo apt install oracle-java8-installer

When you run the commands above you’ll be prompted to access the license terms of the software… accept and continue..

![](images/Screenshot.png)

>sudo apt install oracle-java8-set-default

The command above will automatically set Java 9 as the default… and that should complete your installation, you can check you java version by running following command.

>javac -version

Step 2: Download Eclipse Oxygen

From the link below download eclipse Oxygen IDE package for your system..

https://www.eclipse.org/downloads/

![](images/Screenshot1.png)

Extract the downloaded package to the /opt directory using the commands below… by default Eclipse package should be downloaded into the ~/Downloads folder of your home directory…

Step 3: Install Eclipse IDE

Use the commands below to extract the content in the  ~/Downloads folder… The next line launches the installer…

> tar xfz ~/Downloads/eclipse-inst-linux64.tar.gz
> ~/Downloads/eclipse-installer/eclipse-inst

Select the package IDE you want to install and continue…

![](images/Screenshot2.png)

Use the onscreen instructions to complete the installer.. Accept the default installation directory and continue

![](images/Screenshot4.png)

Next, accept the license terms and continue… wait for Eclipse installer to download and install all the packages..

![](images/Screenshot5.png)

After downloading the installer should complete… all you have to do is launch the program…

![](images/Screenshot6.png)

Step 3: Create Eclipse App Launcher

Run the command below

>nano .local/share/applications/eclipse.desktop

Next, copy and paste the content below into the file and save

>[Desktop Entry]

>Name=Eclipse JEE Oxygen

>Type=Application

>Exec=/home/#govind/eclipse/jee-oxygen/eclipse/eclipse

>Terminal=false

>Icon=/home/#govind/eclipse/jee-oxygen/eclipse/icon.xpm

>Comment=Integrated Development Environment

>NoDisplay=false

>Categories=Development;IDE;

>Name[en]=Eclipse

Replace the highlighted username (govind) with your own account name… also, the Exec = location and icon.xpm should depend on where Eclipse got installed on your system..

Save the file and exit…

You should then have a launcher for Eclipse JEE Oxygen… open Dash or the activities overview and search for Eclipse… then launch.

## API Reference
(https://www.cprogramming.com/tutorial/c-tutorial.html?inl=pf)

## Tests
Describe and show how to run the tests with code examples.

## License

MIT © [Govind raj]()
