using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace NotificationSystem
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Main_Load(object sender, EventArgs e)
        {
            lblUserName.Text = "Welcome " + Global.username;
            UpdateDashboard();
        }

        private void picNotification_Paint(object sender, PaintEventArgs e)
        {
            using (Font myFont = new Font("Arial", 14))
            {
                e.Graphics.DrawString(Global.NotificationCount.ToString(), myFont, Brushes.Red, new Point(2, 2));
            }
        }

        private void UpdateDashboard()
        {
            List<string>lst = Connection.Instance.selectItemRange(1, 3);
            int top = 20, left = 20, width = 250, height = 150, cnt = 0;
            foreach (string item in lst)
            {
                string str  = Connection.Instance.selectItemDetails(item);
                if (str.Equals(string.Empty))
                    continue;
                Label lbl = new Label();
                lbl.Text = str;
                lbl.Top = top;
                lbl.Left = left;
                lbl.Width = width;
                lbl.Height = height;
                lbl.AutoSize = false;
                lbl.BackColor = Color.DarkSeaGreen;
                pnlMain.Controls.Add(lbl);
                cnt++;

                if (cnt % 4 == 0)
                {
                    top += height + 20;
                    left = 20;
                }
                else
                {
                    left += width + 20;
                }
            }
            lblMain.BackColor = Color.MediumTurquoise;
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (txtSearch.Text.Equals(string.Empty))
                return;

            string str = Connection.Instance.selectItemDetails(txtSearch.Text);
            if (str.Equals(string.Empty))
                return;
            Label lbl = new Label();
            lbl.Text = str;
            lbl.Top = 20;
            lbl.Left = 20;
            lbl.Width = 250;
            lbl.Height = 150;
            lbl.AutoSize = false;
            lbl.BackColor = Color.DarkSeaGreen;
            pnlMain.Controls.Clear();
            pnlMain.Controls.Add(lbl);

            lblMain.BackColor = Color.CadetBlue;
        }

        private void lblNotification_Click(object sender, EventArgs e)
        {
            this.Hide();
            Global.notificationfrm.Show();
        }
    }
}
