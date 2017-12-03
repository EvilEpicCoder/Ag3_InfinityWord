## Ag3_InfinityWord
### Word list generator
[![base](https://img.shields.io/badge/EEC-Forensic-red.svg)](https://img.shields.io/badge/EvilEpicCoder-Information--repo-red.svg)
[![base](https://img.shields.io/badge/Status-Active-red.svg)](https://img.shields.io/badge/EvilEpicCoder-Information--repo-red.svg)
[![GitHub license](https://img.shields.io/github/license/EvilEpicCoder/Ag3_InfinityWord.svg)](https://github.com/EvilEpicCoder/Ag3_InfinityWord/blob/master/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/EvilEpicCoder/Ag3_InfinityWord.svg)](https://github.com/EvilEpicCoder/Ag3_InfinityWord/issues)
[![GitHub forks](https://img.shields.io/github/forks/EvilEpicCoder/Ag3_InfinityWord.svg)](https://github.com/EvilEpicCoder/Ag3_InfinityWord/network)
[![GitHub stars](https://img.shields.io/github/stars/EvilEpicCoder/Ag3_InfinityWord.svg)](https://github.com/EvilEpicCoder/Ag3_InfinityWord/stargazers)
[![Build Status](https://travis-ci.org/EvilEpicCoder/Ag3_InfinityWord.svg?branch=master)](https://travis-ci.org/EvilEpicCoder/Ag3_InfinityWord)

[![Twitter](https://img.shields.io/twitter/url/https/github.com/EvilEpicCoder/Ag3_InfinityWord.svg?style=social)](https://twitter.com/intent/tweet?text=Wow:&url=https%3A%2F%2Fgithub.com%2FEvilEpicCoder%2FAg3_InfinityWord)
#### 1.Project
 * Project created for trancode EN to RU word list
 * Why it created, which problens solved:
  If you like write password on russian like "котик" but do
  not change keyboard layout you will had "rjnbr", so my utility deal with it.
 * Require support by write a code, see: [ISSUE_TEMPLATE](https://github.com/EvilEpicCoder/Ag3_InfinityWord/blob/master/ISSUE_TEMPLATE.md)
#### 2. What I use in this project
 * Frameworks : C++ (C plus plus code) Windows/Linux, NodeJS (v6.12.0)
 * Project collect two separates projects (C++ and NodeJS)
#### 3. Instructions
  * How to use for C++:
  ```
  Ag3_InfinityWord -i input.list -o output.list -c RU2EN -a dd.mm.yyyy
  //will decode from Russian to English and add (your) date till current date
  ```
  next snippet
  ```
  Ag3_InfinityWord --input input.list --output output.list --code NONE --add dd.mm.yyyy-dd.mm.yyyy
  //will add (your) date(min) till (your) another date(max)
  ```
  * How to use for NodeJS:
  For now (probably temporary) you need edit Ag3_module_Nodejs.js file. line 4.
  Structure same: input.file output.file, code, special character, numbers
  ```
  convert('/Wordlists_Base/ru_boys.list','/Wordlists_Base/file0011.txt','RU2EN','_',99);
  ```

  * Time consumption
  * What I learned

  Version: `0.2a`
  Date: `12.11.2017`
