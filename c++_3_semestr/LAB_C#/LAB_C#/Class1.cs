using System;
using System.Windows.Forms;

namespace GeographicalEntities
{
    public partial class MainForm : Form
    {
        private City city;
        private Region region;
        private Megapolis megapolis;

        public MainForm()
        {
            InitializeComponent();
        }

        private void btnCreateCity_Click(object sender, EventArgs e)
        {
            try
            {
                string cityName = txtCityName.Text;
                int population = int.Parse(txtCityPopulation.Text);
                city = new City("Россия", cityName, population);
                MessageBox.Show("Город создан!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }

        private void btnCreateRegion_Click(object sender, EventArgs e)
        {
            try
            {
                string regionName = txtRegionName.Text;
                int regionNumber = int.Parse(txtRegionNumber.Text);
                region = new Region("Россия", regionName, regionNumber);
                MessageBox.Show("Регион создан!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }

        private void btnCreateMegapolis_Click(object sender, EventArgs e)
        {
            try
            {
                string megapolisName = txtMegapolisName.Text;
                int population = int.Parse(txtMegapolisPopulation.Text);
                string regionName = txtMegapolisRegionName.Text;
                int regionNumber = int.Parse(txtMegapolisRegionNumber.Text);
                int area = int.Parse(txtMegapolisArea.Text);
                megapolis = new Megapolis("Россия", megapolisName, population, regionName, regionNumber, area);
                MessageBox.Show("Мегаполис создан!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }

        private void btnShowInfo_Click(object sender, EventArgs e)
        {
            string info = "";
            if (city != null)
            {
                info += city.Display() + "\n";
            }
            if (region != null)
            {
                info += region.Display() + "\n";
            }
            if (megapolis != null)
            {
                info += megapolis.Display() + "\n";
            }
            MessageBox.Show(info);
        }
    }

    public abstract class GeographicalEntity
    {
        public abstract string Display();
    }

    public class Place : GeographicalEntity
    {
        protected string Country;

        public Place(string country)
        {
            Country = country;
        }

        public override string Display()
        {
            return $"Страна: {Country}";
        }
    }

    public class City : Place
    {
        private string CityName;
        private int CityPopulation;

        public City(string country, string cityName, int cityPopulation) : base(country)
        {
            CityName = cityName;
            CityPopulation = cityPopulation;
        }

        public override string Display()
        {
            return base.Display() + $"\nГород: {CityName}, Население: {CityPopulation}";
        }
    }

    public class Region : Place
    {
        private string RegionName;
        private int RegionNumber;

        public Region(string country, string regionName, int regionNumber) : base(country)
        {
            RegionName = regionName;
            RegionNumber = regionNumber;
        }

        public override string Display()
        {
            return base.Display() + $"\nРегион: {RegionName}, Номер региона: {RegionNumber}";
        }
    }

    public class Megapolis : City
    {
        private int Area;

        public Megapolis(string country, string cityName, int population, string regionName, int regionNumber, int area)
            : base(country, cityName, population)
        {
            Area = area;
        }

        public override string Display()
        {
            return base.Display() + $"\nПлощадь мегаполиса: {Area} кв. км";
        }
    }
}

Найти еще
