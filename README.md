botTetris
---------

[![Build Status](https://travis-ci.com/lunatikub/botTetris.svg?branch=main)](https://travis-ci.com/lunatikub/botTetris)

# Table of content

- [Getting Started](#section-id-1)
  - [Prerequisites](#section-id-11)
    - [Getting Meson](#section-id-111)
    - [Ninja](#section-id-112)
    - [Installing Meson with pip](#section-id-113)
  - [Installing](#section-id-12)
- [Running the tests](#section-id-2)
- [Built with](#section-id-3)

<div id='section-id-1'/>

# Getting Started

<div id='section-id-11'/>

## Prerequisites

We are using the [Meson Build System](https://mesonbuild.com/index.html) to build the project.
Meson is an open source build system meant to be both extremely fast, and even more importantly, as user friendly as possible.

<div id='section-id-111'/>

### Getting Meson

Meson is implemented in Python 3, and requires 3.5 or newer. If your operating system provides a package manager, you should install it with that.

``` bash
apt-get install python3 python3-pip
yum install python3 python3-pip
```

<div id='section-id-112'/>

### Ninja

Meson needs the [ninja](https://ninja-build.org/) executable.
It is a small build system with a focus on speed.
You can use the version provided by your package manager if possible, otherwise download the binary executable from the Ninja project's release page.

``` bash
apt-get install ninja
yum install ninja
```

<div id='section-id-113'/>

### Installing Meson with pip

You can use the following to install meson for your user and does not require any special privileges.
This will install the package in **~/.local/**, so you will have to add **~/.local/bin** to your PATH.

``` bash
pip3 install --user meson
```

<div id='section-id-12'/>

## Installing

Create a build directory by the simple following command from the root directory.

``` bash
meson <build-dir-name>
```

Compile the project.

``` bash
cd <build-dir-name>
ninja
```

Install the project.

``` bash
cd <build-dir-name>
ninja install
```

<div id='section-id-2'/>

# Running the tests

To run all the tests.

``` bash
cd <build-dir-name>
ninja test
```

<div id='section-id-3'/>

# Built with

* [googletest](https://github.com/abseil/googletest): google Test is a unit testing library for the C/C++ programming language.
