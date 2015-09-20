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
    public partial class Notification : Form
    {
        List<string> lst;
        string condition = "";

        public Notification()
        {
            InitializeComponent();
        }

        private void Notification_Load(object sender, EventArgs e)
        {
            lblConditionDes.Text = "";
            UpdateConditionBoard();
        }

        private void UpdateConditionBoard()
        {
            lst = Connection.Instance.GetConditions(Global.username);
            int top = 36, left = 22, width = 206 , height = 36,cnt = 1;
            foreach (string item in lst)
            {
                Label lbl = new Label();
                lbl.Text = "Condition "+cnt.ToString();
                lbl.Top = top;
                lbl.Left = left;
                lbl.Width = width;
                lbl.Height = height;
                lbl.AutoSize = false;
                lbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 16, FontStyle.Bold);
                lbl.ForeColor = Color.LightGreen;
                lbl.Click += new EventHandler(lblConditions_Click);
                pnlCondition.Controls.Add(lbl);

                top += height + 20;
                cnt++;
            }
        }

        private void lblMain_Click(object sender, EventArgs e)
        {
            this.Hide();
            Global.mainfrm.Show();
        }

        private void lblConditions_Click(object sender, EventArgs e)
        {
            string str = ((Label)sender).Text;
            int n = 0;
            if (!Int32.TryParse(str[str.Length - 1].ToString(),out  n))
                return;
            lblConditionDes.Text = lst[n-1];
        }

        private void btnAND_Click(object sender, EventArgs e)
        {            
            lblConditionDes.Text += condition+" "+ txtAttributeName.Text + " = " + txtAttributeValue.Text +"   " ;
            condition = "AND";
        }

        private void btnOR_Click(object sender, EventArgs e)
        {
            lblConditionDes.Text += condition + " " + txtAttributeName.Text + " = " + txtAttributeValue.Text + "   ";
            condition = "OR";
        }
    }
}
