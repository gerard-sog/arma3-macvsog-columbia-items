class CfgPatches
{
    class prc77battery 
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
    class colsog_inv_prc77_battery: CA_Magazine
    {
        author = "Gerard";
        mass = 44;
        scope = 2;
        value = 1;
        displayName = "PRC-77 Battery";
        picture = "\prc77battery\icons\icon.paa";
        model = "\prc77battery\objects\prc77battery.p3d";
        type = 256;
        count = 1;
        initSpeed = 18;
        nameSound = "handgrenade";
        maxLeadSpeed = 6.94444;
        descriptionShort = "PRC-77 Battery";
        displayNameShort = "PRC-77 Battery";
    };
};