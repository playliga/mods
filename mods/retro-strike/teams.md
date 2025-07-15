# List of Teams

## Americas

- https://web.archive.org/web/20050323045434/http://www.caleague.com/?page=teams&division=csi
- https://web.archive.org/web/20050716103854/http://www.caleague.com/?division=csp&page=teams

```sql
SELECT
    t.*
FROM
    Team t
JOIN
    Country c ON t.countryId = c.id
JOIN
    Continent co ON c.continentId = co.id
JOIN
    Federation f ON co.federationId = f.id
WHERE
    f.name = "Electronic Sports Americas"
AND
    t.tier = 4;
```

- (br=31, id=81) g3nerationX
  - aliche
  - crash
  - gAuLeS
  - ApReNdIz
  - bruno
  - Apoka
- (br=31, id=82) mibr
  - cogu
  - Eduzin
  - Pred
  - KIKO
  - pava
- (us=233, id=83) Team 3D
  - rambo
  - moto
  - cbz
  - KSharp
  - Volcano
  - boms
- (us=233, id=84) compLexity
  - fRoD
  - Bullseye
  - Warden
  - Storm
  - sunman
  - tr1p
- (ca=38, id=85) Evil Geniuses
  - chinsquad
  - Lin
  - blackpanther
  - (us=233) da_bears
  - Stevenson
- (us=233, id=86) United 5
  - Hare
  - moses
  - PaTyoJoN
  - BatMaN
  - hostile
  - kmode
- (us=233, id=87) zEx
  - reCTOOOOR
  - aimeTTi
  - dkt
  - Titus
  - hicCKEEEEY
  - i0nZ
- (us=233, id=88) Mug N' Mouse
  - MuMiX
  - punkville
  - go0ber
  - Tower
  - JaysoN
  - Gosu
- (us=233, id=89) CheckSix Gaming
  - HolyMan
  - m4gic
  - evaN
  - taylor
  - royle
  - TusHarZ
- (us=233, id=90) Team D!E
  - killabeez
  - Slick
  - CuZ-1H
  - kEEn
  - IceMaN
  - fishymaN
- (us=233, id=91) Green Berets
  - jame^s
  - mehLer
  - LuckyTed
  - TriPPinG
  - KaMi
- (us=233, id=92) Meepins
  - gK
  - Fierce
  - bombsqd
  - cobalt
  - hoon
  - sPaG
- (us=233, id=93) Team Pandemic
  - MadMaxx
  - cRAMBLOCk
  - amessner
  - griff
  - Haplo
  - biLwauLke
- (us=233, id=94) Team Rival
  - hanes
  - exodus
  - Ph33R
  - Masternook
  - ???
- (us=233, id=95) TEC
  - derosa
  - SpYdeR
  - Gouki
  - t0oL[1g]
  - elude
  - bzrk
- (us=233, id=96) Team Turmoil
  - Bruin
  - chaos
  - jaded
  - SuperBug
  - goodfornothing
  - hahN
- (ca=38, id=97) JaX Money Crew
  - jasido
  - foomy
  - krupt
  - rodman
  - Royle
  - (us=233) sm0og1er
- (us=233, id=98) Weekend Warriors
  - sinyster
  - Loh
  - jout
  - cLowN
  - Ph0bius
  - LEEZOR
- (us=233, id=99) Blindside
  - shortehh
  - ducKy
  - invisibleninja
  - spifdo
  - eps
  - darb
- (ca=38, id=100) DeadZone
  - Talon
  - Teknikal
  - arKael
  - KyRo
  - axel
  - maUk

## Europa

- https://liquipedia.net/counterstrike/2005_CPL_Winter_Championship
- https://liquipedia.net/counterstrike/ClanBase/EuroCup/XI/Online_Stage

```sql
SELECT
    t.*
FROM
    Team t
JOIN
    Country c ON t.countryId = c.id
JOIN
    Continent co ON c.continentId = co.id
JOIN
    Federation f ON co.federationId = f.id
WHERE
    f.name = "Electronic Sports Europa"
AND
    t.tier = 4;
```

- (swe=197, id=233) SK Gaming
  - SpawN
  - fisker
  - ahl
  - Snajdan
  - vilden
- (swe=197, id=234) Fnatic
  - zaffe
  - dsn
  - Magix
  - (fi=70) diGital
  - MegatoN
- (swe=197, id=235) Ninjas in Pyjamas
  - walle
  - HeatoN
  - zet
  - Potti
  - ins
- (de=57, id=236) Mousesports
  - (at=12) gore
  - Blizzard
  - Roman R.
  - neo
  - (at=12) PapsT
- (swe=197, id=237) Begrip Gaming
  - RobbaN
  - IsKall
  - Calippo
  - Tentpole
  - f0rest
- (uk=77, id=238) 4Kings
  - (swe=197) GoodFella
  - (fi=70) natu
  - (no=167) DaY
  - Mangiacapra
  - aKuJii
- (no=167, id=239) Team Catch-Gamer
  - bsl
  - Juzam
  - zevy
  - Juve9le
  - NaikoN
- (de=57, id=240) mTw
  - (at=12) hades
  - Hanso
  - night
  - roman
  - (at=12) uLTi
- (fi=70, id=241) astralis
  - bloodR
  - tihOp
  - ruuit
  - Kaamos
  - GuadiaN
- (fi=70, id=242) Serious Gaming
  - lurppis
  - kononen
  - toNppa
  - Kuppi
  - contE
- (dk=59, id=243) Meet Your Makers
  - iTzO
  - PaCMaN
  - Wire
  - gAze
  - torM
- (ru=191, id=244) Virtus.Pro
  - F_1N
  - groove
  - LeX
  - hooch
  - Snoop
- (de=57, id=245) ALTERNATE aTTaX
  - silver
  - n!tro
  - voodoo
  - r4id
  - mooN
- (fr=75, id=246) against All authority
  - bisou
  - (cn=48) kyo
  - r0nan
  - KabaL
  - Emkill
- (po=179, id=247) Team Pentagram
  - NEO
  - TaZ
  - zibi
  - LUq
  - ruloN
- (es=68, id=248) x6tence
  - Dev1
  - milicua
  - MusambaN1
  - (arg=10) Ferchu
  - FlipiN
- (dk=59, id=249) The Titans
  - spx
  - calc
  - eGene
  - Drally
  - EraZ
- (dk=59, id=250) NoA
  - knoxville
  - (ca=38) shaGuar
  - (us=233) method
  - nVy
  - damien
- (de=57, id=251) Advanced Online Losers
  - Bodo
  - Fragmaster
  - (po=179) DonKamilo
  - Kapio
  - ToM
- (dk=59, id=252) eoLithic
  - darK
  - XeqtR
  - elemeNt
  - Luke
