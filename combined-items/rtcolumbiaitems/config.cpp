class CfgPatches
{
    class rtcolumbiaitems 
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
    class colsog_inv_handsid_sensor: CA_Magazine
    {
        author = "Gerard";
        mass = 100;
        scope = 2;
        value = 1;
        displayName = "Handsid sensor";
        picture = "\rtcolumbiaitems\icons\iconHandsidSensor.paa";
        model = "\rtcolumbiaitems\objects\handsidsensor.p3d";
        type = 256;
        count = 1;
        initSpeed = 18;
        nameSound = "handgrenade";
        maxLeadSpeed = 6.94444;
        descriptionShort = "Handsid sensor";
        displayNameShort = "Handsid sensor";
    };
    class colsog_inv_prc77_battery: CA_Magazine
    {
        author = "Gerard";
        mass = 44;
        scope = 2;
        value = 1;
        displayName = "PRC-77 Battery";
        picture = "\rtcolumbiaitems\icons\iconPrc77Battery.paa";
        model = "\rtcolumbiaitems\objects\prc77battery.p3d";
        type = 256;
        count = 1;
        initSpeed = 18;
        nameSound = "handgrenade";
        maxLeadSpeed = 6.94444;
        descriptionShort = "PRC-77 Battery";
        displayNameShort = "PRC-77 Battery";
    };
    class colsog_inv_sensor: CA_Magazine
    {
        author = "Gerard";
        mass = 15;
        scope = 2;
        value = 1;
        displayName = "Seismic sensor";
        picture = "\rtcolumbiaitems\icons\iconSeismicSensor.paa";
        model = "\rtcolumbiaitems\objects\seismicsensor.p3d";
        type = 256;
        count = 1;
        initSpeed = 18;
        nameSound = "handgrenade";
        maxLeadSpeed = 6.94444;
        descriptionShort = "Seismic sensor";
        displayNameShort = "Seismic sensor";
    };
};