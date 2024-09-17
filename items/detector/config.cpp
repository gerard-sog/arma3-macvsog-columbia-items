class CfgPatches
{
    class detector
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
    class colsog_inv_detector: CA_Magazine
    {
        author = "Gerard";
        mass = 20;
        scope = 2;
        value = 1;
        displayName = "Seismic sensor";
        picture = "\detector\icons\detector_icon.paa";
        model = "\detector\objects\detector.p3d";
        type = 256;
        count = 1;
        initSpeed = 18;
        nameSound = "handgrenade";
        maxLeadSpeed = 6.94444;
        descriptionShort = "Seismic sensor";
        displayNameShort = "Seismic sensor";
    };
};
