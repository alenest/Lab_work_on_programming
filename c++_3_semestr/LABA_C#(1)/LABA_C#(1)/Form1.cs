using System;
using System.Drawing;
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
            InitializePlaceholder();

            // Запретить максимизацию окна
            this.MaximizeBox = false;
            this.FormBorderStyle = FormBorderStyle.FixedSingle; // Запретить изменение размера окна

            // Привязка обработчиков событий для ограничения ввода
            txtCityName.KeyPress += TextBox_KeyPress;
            txtCityPopulation.KeyPress += TextBox_KeyPress;
            txtRegionName.KeyPress += TextBox_KeyPress;
            txtRegionNumber.KeyPress += TextBox_KeyPress;
            txtMegapolisName.KeyPress += TextBox_KeyPress;
            txtMegapolisPopulation.KeyPress += TextBox_KeyPress;
            txtMegapolisRegionName.KeyPress += TextBox_KeyPress;
            txtMegapolisRegionNumber.KeyPress += TextBox_KeyPress;
            txtMegapolisArea.KeyPress += TextBox_KeyPress;
        }

        private void InitializePlaceholder()
        {
            SetPlaceholder(txtCityName, "Название города");
            SetPlaceholder(txtCityPopulation, "Население города");
            SetPlaceholder(txtRegionName, "Название региона");
            SetPlaceholder(txtRegionNumber, "Номер региона");
            SetPlaceholder(txtMegapolisName, "Название мегаполиса");
            SetPlaceholder(txtMegapolisPopulation, "Население мегаполиса");
            SetPlaceholder(txtMegapolisRegionName, "Название региона мегаполиса");
            SetPlaceholder(txtMegapolisRegionNumber, "Номер региона мегаполиса");
            SetPlaceholder(txtMegapolisArea, "Площадь мегаполиса");
        }

        private void SetPlaceholder(TextBox textBox, string placeholder)
        {
            textBox.Text = placeholder;
            textBox.ForeColor = Color.Gray;

            textBox.Enter += (sender, e) =>
            {
                if (textBox.Text == placeholder)
                {
                    textBox.Text = "";
                    textBox.ForeColor = Color.Black;
                }
            };

            textBox.Leave += (sender, e) =>
            {
                if (string.IsNullOrWhiteSpace(textBox.Text))
                {
                    textBox.Text = placeholder;
                    textBox.ForeColor = Color.Gray;
                }
            };
        }

        private void TextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            TextBox textBox = sender as TextBox;
            if (textBox != null && textBox.Text.Length >= 15 && !char.IsControl(e.KeyChar))
            {
                e.Handled = true; // Отменяем ввод
                MessageBox.Show("Ошибка: максимальная длина ввода - 15 символов.", "Ошибка ввода", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void btnCreateCity_Click(object sender, EventArgs e)
        {
            try
            {
                string cityName = txtCityName.Text;
                if (string.IsNullOrWhiteSpace(cityName) || cityName == "Название города")
                {
                    MessageBox.Show("Ошибка: название города не может быть пустым.");
                    return;
                }

                if (cityName.Length >= 15)
                {
                    MessageBox.Show("Ошибка: название города не должно превышать 15 символов.");
                    return;
                }

                string cityPopulationText = txtCityPopulation.Text;
                if (cityPopulationText.Length >= 15)
                {
                    MessageBox.Show("Ошибка: население не должно превышать 15 символов.");
                    return;
                }

                int population;
                if (!int.TryParse(cityPopulationText, out population) || population < 1)
                {
                    MessageBox.Show("Ошибка: население должно быть числом и больше или равно 1.");
                    return;
                }

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
                if (string.IsNullOrWhiteSpace(regionName) || regionName == "Название региона")
                {
                    MessageBox.Show("Ошибка: название региона не может быть пустым.");
                    return;
                }

                if (regionName.Length > 15)
                {
                    MessageBox.Show("Ошибка: название региона не должно превышать 15 символов.");
                    return;
                }

                string regionNumberText = txtRegionNumber.Text;
                if (regionNumberText.Length >= 15)
                {
                    MessageBox.Show("Ошибка: номер региона не должен превышать 15 символов.");
                    return;
                }

                int regionNumber;
                if (!int.TryParse(regionNumberText, out regionNumber))
                {
                    MessageBox.Show("Ошибка: номер региона должен быть числом.");
                    return;
                }

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
                if (string.IsNullOrWhiteSpace(megapolisName) || megapolisName == "Название мегаполиса")
                {
                    MessageBox.Show("Ошибка: название мегаполиса не может быть пустым.");
                    return;
                }

                if (megapolisName.Length >= 15)
                {
                    MessageBox.Show("Ошибка: название мегаполиса не должно превышать 15 символов.");
                    return;
                }

                string megapolisPopulationText = txtMegapolisPopulation.Text;
                if (megapolisPopulationText.Length >= 15)
                {
                    MessageBox.Show("Ошибка: население не должно превышать 15 символов.");
                    return;
                }

                int population;
                if (!int.TryParse(megapolisPopulationText, out population) || population < 1)
                {
                    MessageBox.Show("Ошибка: население должно быть числом и больше или равно 1.");
                    return;
                }

                string regionName = txtMegapolisRegionName.Text;
                if (string.IsNullOrWhiteSpace(regionName) || regionName == "Название региона мегаполиса")
                {
                    MessageBox.Show("Ошибка: название региона мегаполиса не может быть пустым.");
                    return;
                }

                if (regionName.Length >= 15)
                {
                    MessageBox.Show("Ошибка: название региона мегаполиса не должно превышать 15 символов.");
                    return;
                }

                string megapolisRegionNumberText = txtMegapolisRegionNumber.Text;
                if (megapolisRegionNumberText.Length >= 15)
                {
                    MessageBox.Show("Ошибка: номер региона не должен превышать 15 символов.");
                    return;
                }

                int regionNumber;
                if (!int.TryParse(megapolisRegionNumberText, out regionNumber))
                {
                    MessageBox.Show("Ошибка: номер региона должен быть числом.");
                    return;
                }

                string megapolisAreaText = txtMegapolisArea.Text;
                if (megapolisAreaText.Length >= 15)
                {
                    MessageBox.Show("Ошибка: площадь не должна превышать 15 символов.");
                    return;
                }

                int area;
                if (!int.TryParse(megapolisAreaText, out area) || area < 1)
                {
                    MessageBox.Show("Ошибка: площадь должна быть числом и больше или равно 1.");
                    return;
                }

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
            return string.Empty;
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
            return base.Display() + $"\nПлощадь: {Area}";
        }
    }
}






//using System;
//using System.Drawing;
//using System.Windows.Forms;

//namespace GeographicalEntities
//{
//    public partial class MainForm : Form
//    {
//        private City city;
//        private Region region;
//        private Megapolis megapolis;

//        public MainForm()
//        {
//            InitializeComponent();
//            InitializePlaceholder();

//            // Запретить максимизацию окна
//            this.MaximizeBox = false;
//            this.FormBorderStyle = FormBorderStyle.FixedSingle; // Запретить изменение размера окна
//        }

//        private void InitializePlaceholder()
//        {
//            SetPlaceholder(txtCityName, "Название города");
//            SetPlaceholder(txtCityPopulation, "Население города");
//            SetPlaceholder(txtRegionName, "Название региона");
//            SetPlaceholder(txtRegionNumber, "Номер региона");
//            SetPlaceholder(txtMegapolisName, "Название мегаполиса");
//            SetPlaceholder(txtMegapolisPopulation, "Население мегаполиса");
//            SetPlaceholder(txtMegapolisRegionName, "Название региона мегаполиса");
//            SetPlaceholder(txtMegapolisRegionNumber, "Номер региона мегаполиса");
//            SetPlaceholder(txtMegapolisArea, "Площадь мегаполиса");
//        }

//        private void SetPlaceholder(TextBox textBox, string placeholder)
//        {
//            textBox.Text = placeholder;
//            textBox.ForeColor = Color.Gray;

//            textBox.Enter += (sender, e) =>
//            {
//                if (textBox.Text == placeholder)
//                {
//                    textBox.Text = "";
//                    textBox.ForeColor = Color.Black;
//                }
//            };

//            textBox.Leave += (sender, e) =>
//            {
//                if (string.IsNullOrWhiteSpace(textBox.Text))
//                {
//                    textBox.Text = placeholder;
//                    textBox.ForeColor = Color.Gray;
//                }
//            };
//        }

//        private void btnCreateCity_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string cityName = txtCityName.Text;
//                if (string.IsNullOrWhiteSpace(cityName) || cityName == "Название города")
//                {
//                    MessageBox.Show("Ошибка: название города не может быть пустым.");
//                    return;
//                }

//                int population;
//                if (!int.TryParse(txtCityPopulation.Text, out population))
//                {
//                    MessageBox.Show("Ошибка: население должно быть числом.");
//                    return;
//                }

//                city = new City("Россия", cityName, population);
//                MessageBox.Show("Город создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnCreateRegion_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string regionName = txtRegionName.Text;
//                if (string.IsNullOrWhiteSpace(regionName) || regionName == "Название региона")
//                {
//                    MessageBox.Show("Ошибка: название региона не может быть пустым.");
//                    return;
//                }

//                int regionNumber;
//                if (!int.TryParse(txtRegionNumber.Text, out regionNumber))
//                {
//                    MessageBox.Show("Ошибка: номер региона должен быть числом.");
//                    return;
//                }

//                region = new Region("Россия", regionName, regionNumber);
//                MessageBox.Show("Регион создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnCreateMegapolis_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string megapolisName = txtMegapolisName.Text;
//                if (string.IsNullOrWhiteSpace(megapolisName) || megapolisName == "Название мегаполиса")
//                {
//                    MessageBox.Show("Ошибка: название мегаполиса не может быть пустым.");
//                    return;
//                }

//                int population;
//                if (!int.TryParse(txtMegapolisPopulation.Text, out population))
//                {
//                    MessageBox.Show("Ошибка: население должно быть числом.");
//                    return;
//                }

//                string regionName = txtMegapolisRegionName.Text;
//                if (string.IsNullOrWhiteSpace(regionName) || regionName == "Название региона мегаполиса")
//                {
//                    MessageBox.Show("Ошибка: название региона мегаполиса не может быть пустым.");
//                    return;
//                }

//                int regionNumber;
//                if (!int.TryParse(txtMegapolisRegionNumber.Text, out regionNumber))
//                {
//                    MessageBox.Show("Ошибка: номер региона должен быть числом.");
//                    return;
//                }

//                int area;
//                if (!int.TryParse(txtMegapolisArea.Text, out area))
//                {
//                    MessageBox.Show("Ошибка: площадь должна быть числом.");
//                    return;
//                }

//                megapolis = new Megapolis("Россия", megapolisName, population, regionName, regionNumber, area);
//                MessageBox.Show("Мегаполис создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnShowInfo_Click(object sender, EventArgs e)
//        {
//            string info = "";
//            if (city != null)
//            {
//                info += city.Display() + "\n";
//            }
//            if (region != null)
//            {
//                info += region.Display() + "\n";
//            }
//            if (megapolis != null)
//            {
//                info += megapolis.Display() + "\n";
//            }
//            MessageBox.Show(info);
//        }
//    }

//    public abstract class GeographicalEntity
//    {
//        public abstract string Display();
//    }

//    public class Place : GeographicalEntity
//    {
//        protected string Country;

//        public Place(string country)
//        {
//            Country = country;
//        }

//        public override string Display()
//        {
//            //return $"Страна: {Country}";
//            return string.Empty;
//        }
//    }

//    public class City : Place
//    {
//        private string CityName;
//        private int CityPopulation;

//        public City(string country, string cityName, int cityPopulation) : base(country)
//        {
//            CityName = cityName;
//            CityPopulation = cityPopulation;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nГород: {CityName}, Население: {CityPopulation}";
//        }
//    }

//    public class Region : Place
//    {
//        private string RegionName;
//        private int RegionNumber;

//        public Region(string country, string regionName, int regionNumber) : base(country)
//        {
//            RegionName = regionName;
//            RegionNumber = regionNumber;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nРегион: {RegionName}, Номер региона: {RegionNumber}";
//        }
//    }

//    public class Megapolis : City
//    {
//        private int Area;

//        public Megapolis(string country, string cityName, int population, string regionName, int regionNumber, int area)
//            : base(country, cityName, population)
//        {
//            Area = area;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nПлощадь: {Area}";
//        }
//    }
//}

//using System;
//using System.Drawing;
//using System.Windows.Forms;

//namespace GeographicalEntities
//{
//    public partial class MainForm : Form
//    {
//        private City city;
//        private Region region;
//        private Megapolis megapolis;

//        public MainForm()
//        {
//            InitializeComponent();
//            InitializePlaceholder();
//        }

//        private void InitializePlaceholder()
//        {
//            SetPlaceholder(txtCityName, "Название города");
//            SetPlaceholder(txtCityPopulation, "Население города");
//            SetPlaceholder(txtRegionName, "Название региона");
//            SetPlaceholder(txtRegionNumber, "Номер региона");
//            SetPlaceholder(txtMegapolisName, "Название мегаполиса");
//            SetPlaceholder(txtMegapolisPopulation, "Население мегаполиса");
//            SetPlaceholder(txtMegapolisRegionName, "Название региона мегаполиса");
//            SetPlaceholder(txtMegapolisRegionNumber, "Номер региона мегаполиса");
//            SetPlaceholder(txtMegapolisArea, "Площадь мегаполиса");
//        }

//        private void SetPlaceholder(TextBox textBox, string placeholder)
//        {
//            textBox.Text = placeholder;
//            textBox.ForeColor = Color.Gray;

//            textBox.Enter += (sender, e) =>
//            {
//                if (textBox.Text == placeholder)
//                {
//                    textBox.Text = "";
//                    textBox.ForeColor = Color.Black;
//                }
//            };

//            textBox.Leave += (sender, e) =>
//            {
//                if (string.IsNullOrWhiteSpace(textBox.Text))
//                {
//                    textBox.Text = placeholder;
//                    textBox.ForeColor = Color.Gray;
//                }
//            };
//        }

//        //private void btnCreateCity_Click(object sender, EventArgs e)
//        //{
//        //    try
//        //    {
//        //        string cityName = txtCityName.Text;
//        //        int population = int.Parse(txtCityPopulation.Text);
//        //        city = new City("Россия", cityName, population);
//        //        MessageBox.Show("Город создан!");
//        //    }
//        //    catch (Exception ex)
//        //    {
//        //        MessageBox.Show($"Ошибка: {ex.Message}");
//        //    }
//        //}

//        //private void btnCreateRegion_Click(object sender, EventArgs e)
//        //{
//        //    try
//        //    {
//        //        string regionName = txtRegionName.Text;
//        //        int regionNumber = int.Parse(txtRegionNumber.Text);
//        //        region = new Region("Россия", regionName, regionNumber);
//        //        MessageBox.Show("Регион создан!");
//        //    }
//        //    catch (Exception ex)
//        //    {
//        //        MessageBox.Show($"Ошибка: {ex.Message}");
//        //    }
//        //}

//        //private void btnCreateMegapolis_Click(object sender, EventArgs e)
//        //{
//        //    try
//        //    {
//        //        string megapolisName = txtMegapolisName.Text;
//        //        int population = int.Parse(txtMegapolisPopulation.Text);
//        //        string regionName = txtMegapolisRegionName.Text;
//        //        int regionNumber = int.Parse(txtMegapolisRegionNumber.Text);
//        //        int area = int.Parse(txtMegapolisArea.Text);
//        //        megapolis = new Megapolis("Россия", megapolisName, population, regionName, regionNumber, area);
//        //        MessageBox.Show("Мегаполис создан!");
//        //    }
//        //    catch (Exception ex)
//        //    {
//        //        MessageBox.Show($"Ошибка: {ex.Message}");
//        //    }
//        //}

//        private void btnCreateCity_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string cityName = txtCityName.Text;
//                if (string.IsNullOrWhiteSpace(cityName) || cityName == "Название города")
//                {
//                    MessageBox.Show("Ошибка: название города не может быть пустым.");
//                    return;
//                }

//                int population;
//                if (!int.TryParse(txtCityPopulation.Text, out population))
//                {
//                    MessageBox.Show("Ошибка: население должно быть числом.");
//                    return;
//                }

//                city = new City("Россия", cityName, population);
//                MessageBox.Show("Город создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnCreateRegion_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string regionName = txtRegionName.Text;
//                if (string.IsNullOrWhiteSpace(regionName) || regionName == "Название региона")
//                {
//                    MessageBox.Show("Ошибка: название региона не может быть пустым.");
//                    return;
//                }

//                int regionNumber;
//                if (!int.TryParse(txtRegionNumber.Text, out regionNumber))
//                {
//                    MessageBox.Show("Ошибка: номер региона должен быть числом.");
//                    return;
//                }

//                region = new Region("Россия", regionName, regionNumber);
//                MessageBox.Show("Регион создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnCreateMegapolis_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string megapolisName = txtMegapolisName.Text;
//                if (string.IsNullOrWhiteSpace(megapolisName) || megapolisName == "Название мегаполиса")
//                {
//                    MessageBox.Show("Ошибка: название мегаполиса не может быть пустым.");
//                    return;
//                }

//                int population;
//                if (!int.TryParse(txtMegapolisPopulation.Text, out population))
//                {
//                    MessageBox.Show("Ошибка: население должно быть числом.");
//                    return;
//                }

//                string regionName = txtMegapolisRegionName.Text;
//                if (string.IsNullOrWhiteSpace(regionName) || regionName == "Название региона мегаполиса")
//                {
//                    MessageBox.Show("Ошибка: название региона мегаполиса не может быть пустым.");
//                    return;
//                }

//                int regionNumber;
//                if (!int.TryParse(txtMegapolisRegionNumber.Text, out regionNumber))
//                {
//                    MessageBox.Show("Ошибка: номер региона должен быть числом.");
//                    return;
//                }

//                int area;
//                if (!int.TryParse(txtMegapolisArea.Text, out area))
//                {
//                    MessageBox.Show("Ошибка: площадь должна быть числом.");
//                    return;
//                }

//                megapolis = new Megapolis("Россия", megapolisName, population, regionName, regionNumber, area);
//                MessageBox.Show("Мегаполис создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnShowInfo_Click(object sender, EventArgs e)
//        {
//            string info = "";
//            if (city != null)
//            {
//                info += city.Display() + "\n";
//            }
//            if (region != null)
//            {
//                info += region.Display() + "\n";
//            }
//            if (megapolis != null)
//            {
//                info += megapolis.Display() + "\n";
//            }
//            MessageBox.Show(info);
//        }
//    }

//    public abstract class GeographicalEntity
//    {
//        public abstract string Display();
//    }

//    public class Place : GeographicalEntity
//    {
//        protected string Country;

//        public Place(string country)
//        {
//            Country = country;
//        }

//        public override string Display()
//        {
//            return $"Страна: {Country}";
//        }
//    }

//    public class City : Place
//    {
//        private string CityName;
//        private int CityPopulation;

//        public City(string country, string cityName, int cityPopulation) : base(country)
//        {
//            CityName = cityName;
//            CityPopulation = cityPopulation;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nГород: {CityName}, Население: {CityPopulation}";
//        }
//    }

//    public class Region : Place
//    {
//        private string RegionName;
//        private int RegionNumber;

//        public Region(string country, string regionName, int regionNumber) : base(country)
//        {
//            RegionName = regionName;
//            RegionNumber = regionNumber;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nРегион: {RegionName}, Номер региона: {RegionNumber}";
//        }
//    }

//    public class Megapolis : City
//    {
//        private int Area;

//        public Megapolis(string country, string cityName, int population, string regionName, int regionNumber, int area)
//            : base(country, cityName, population)
//        {
//            Area = area;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nПлощадь мегаполиса: {Area} кв. км";
//        }
//    }
//}

//using System;
//using System.Windows.Forms;

//namespace GeographicalEntities
//{
//    public partial class MainForm : Form
//    {
//        private City city;
//        private Region region;
//        private Megapolis megapolis;

//        public MainForm()
//        {
//            InitializeComponent();
//        }

//        private void btnCreateCity_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string cityName = txtCityName.Text;
//                int population = int.Parse(txtCityPopulation.Text);
//                city = new City("Россия", cityName, population);
//                MessageBox.Show("Город создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnCreateRegion_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string regionName = txtRegionName.Text;
//                int regionNumber = int.Parse(txtRegionNumber.Text);
//                region = new Region("Россия", regionName, regionNumber);
//                MessageBox.Show("Регион создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnCreateMegapolis_Click(object sender, EventArgs e)
//        {
//            try
//            {
//                string megapolisName = txtMegapolisName.Text;
//                int population = int.Parse(txtMegapolisPopulation.Text);
//                string regionName = txtMegapolisRegionName.Text;
//                int regionNumber = int.Parse(txtMegapolisRegionNumber.Text);
//                int area = int.Parse(txtMegapolisArea.Text);
//                megapolis = new Megapolis("Россия", megapolisName, population, regionName, regionNumber, area);
//                MessageBox.Show("Мегаполис создан!");
//            }
//            catch (Exception ex)
//            {
//                MessageBox.Show($"Ошибка: {ex.Message}");
//            }
//        }

//        private void btnShowInfo_Click(object sender, EventArgs e)
//        {
//            string info = "";
//            if (city != null)
//            {
//                info += city.Display() + "\n";
//            }
//            if (region != null)
//            {
//                info += region.Display() + "\n";
//            }
//            if (megapolis != null)
//            {
//                info += megapolis.Display() + "\n";
//            }
//            MessageBox.Show(info);
//        }
//    }

//    public abstract class GeographicalEntity
//    {
//        public abstract string Display();
//    }

//    public class Place : GeographicalEntity
//    {
//        protected string Country;

//        public Place(string country)
//        {
//            Country = country;
//        }

//        public override string Display()
//        {
//            return $"Страна: {Country}";
//        }
//    }

//    public class City : Place
//    {
//        private string CityName;
//        private int CityPopulation;

//        public City(string country, string cityName, int cityPopulation) : base(country)
//        {
//            CityName = cityName;
//            CityPopulation = cityPopulation;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nГород: {CityName}, Население: {CityPopulation}";
//        }
//    }

//    public class Region : Place
//    {
//        private string RegionName;
//        private int RegionNumber;

//        public Region(string country, string regionName, int regionNumber) : base(country)
//        {
//            RegionName = regionName;
//            RegionNumber = regionNumber;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nРегион: {RegionName}, Номер региона: {RegionNumber}";
//        }
//    }

//    public class Megapolis : City
//    {
//        private int Area;

//        public Megapolis(string country, string cityName, int population, string regionName, int regionNumber, int area)
//            : base(country, cityName, population)
//        {
//            Area = area;
//        }

//        public override string Display()
//        {
//            return base.Display() + $"\nПлощадь мегаполиса: {Area} кв. км";
//        }
//    }
//}
