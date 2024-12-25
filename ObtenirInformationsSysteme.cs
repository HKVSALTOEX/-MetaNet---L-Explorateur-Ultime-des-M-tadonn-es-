using System;

class ObtenirInformationsSysteme {
    public static void Main(string[] args) {
        Console.WriteLine("Système d'exploitation: " + Environment.OSVersion.Platform);
        Console.WriteLine("Version du système: " + Environment.OSVersion.VersionString);
        Console.WriteLine("Nom de l'ordinateur: " + Environment.MachineName);
    }
}
