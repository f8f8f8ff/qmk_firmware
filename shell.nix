{ pkgs ? (import <nixpkgs> {}).__splicedPackages }:
pkgs.pkgsCross.avr.mkShell {
    nativeBuildInputs = with pkgs; [
        qmk
    ];
}
